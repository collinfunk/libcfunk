#!/usr/bin/env python3

import os
import sys
import re
from pathlib import Path, PurePath

THIS_FILE = Path(__file__).resolve()
THIS_DIR = THIS_FILE.parent

# Regular expression to match "check_symbol_exists(symbol headers variable)"
check_symbol_exists_regexp = re.compile(r"\s*?check_symbol_exists\s*?\(\s*?"
                                        r"(.+?)\s+\"?(.+?)[\"?\s]\s*(.+?)\)")

# Regular expression to match "check_include_file(header variable) or
# check_include_files(headers variable)
check_include_file_regexp = re.compile(r"\s*?check_include_files?\s*?\(\s?"
                                       r"\"?(.+?)[\"?\s]\s*(.+?)\)")

# Regular expresion to match "configure_file(src dest)"
configure_file_regexp = re.compile(r"\s*?configure_file\s*?\(\s*?"
                                   r"(\S+?)\s+?(\S+?)\s*?\)")

# CMake include(file) regular expression.
include_regexp = re.compile(r"\s*?include\s*?\(\s*?(.+?)\s*?\)")

# Regular expression to match target_sources(target property sources ...)
target_sources_regexp = re.compile(r"\s?target_sources\s*?\(\s*?"
                                   r"(.+?)\s+?(INTERFACE|PUBLIC|PRIVATE)\s+?"
                                   r"(.*?)\s*?\)")

# Regular expression to match set(variable value)
set_regexp = re.compile(r"\s?set\s*?\(\*?"
                        r"(.+?)\s+?(.?+)\s*?\)")


def read_file(filename: Path) -> str:
    lines = []
    try:
        with open(filename, "r", encoding="utf-8") as file:
            for line in file:
                lines.append(line)
    finally:
        return "".join(lines)


def find_config_vars(files: list[Path]) -> set:
    """ Returns a set of all the HAVE_* definitions for the config file. """
    variables = set()
    for file in files:
        content = read_file(file)
        headers = re.finditer(check_include_file_regexp, content)
        for header in headers:
            variables.add(header[2])
        symbols = re.finditer(check_symbol_exists_regexp, content)
        for symbol in symbols:
            variables.add(symbol[3])
    return variables


def emit_config_file(files: list[Path]) -> str:
    """ Returns the string to be contained in the config file. """
    variables = list(find_config_vars(files))
    headers = sorted([x for x in variables if x.endswith("_H")])
    symbols = sorted([x for x in variables if not x.endswith("_H")])

    gaurd = "#ifdef CONFIG_H\n#define CONFIG_H\n\n"
    body = "\n".join(["#cmakedefine01 " + x for x in headers + symbols])
    end = "\n\n#endif /* CONFIG_H */"
    return gaurd + body + end


def main() -> None:
    argv = sys.argv
    argc = len(argv)

    if argc < 2:
        print(f"{THIS_FILE} files ...")
        exit(1)

    files = [Path(x).resolve() for x in argv[1:]]
    print(emit_config_file(files))


if __name__ == "__main__":
    main()
