#!/usr/bin/env python3

import os
import sys
import re
from pathlib import Path, PurePath

THIS_FILE = Path(__file__).resolve()
THIS_DIR = THIS_FILE.parent

# Regular expression to match a local include "#include "filename.h""
# Follows traditional preprocessor syntax where no spaces leading the #.
local_include_regexp = re.compile(r"^#\s*?include\s+?\"(.+?)\"", re.MULTILINE)

# Regular expression to match a system include "#include <filename.h>"
# Follows traditional preprocessor syntax where no spaces leading the #.
system_include_regexp = re.compile(r"^#\s*?include\s+?<(.+?)>", re.MULTILINE)

def read_file(filename: Path) -> str:
    lines = []
    try:
        with open(filename, "r", encoding="utf-8") as file:
            for line in file:
                lines.append(line)
    finally:
        return "".join(lines)

def main() -> None:
    argv = sys.argv
    argc = len(argv)

    if argc < 2:
        print(f"{THIS_FILE} files ...")
        exit(1)

    files = [Path(x).resolve() for x in argv[1:]]

    for file in files:
        content = read_file(file)
        local_includes = re.findall(local_include_regexp, content)
        system_includes = re.findall(system_include_regexp, content)
        if not local_includes and not system_includes:
            continue
        print(f"Filename: {file.name}")
        if system_includes:
            system_includes = "\n".join(system_includes)
            print(f"System includes:")
            print(f"{system_includes}")
        if local_includes:
            local_includes = "\n".join(local_includes)
            print(f"Local includes:")
            print(f"{local_includes}")
        print("")

if __name__ == "__main__":
    main()
