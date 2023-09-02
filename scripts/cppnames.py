#!/usr/bin/env python3

from __future__ import annotations
import os
import re
import sys
from pathlib import Path


def read_lines(filename: Path) -> list[str]:
    lines = []
    try:
        with open(filename, encoding='utf-8') as file:
            for line in file:
                line = line.rstrip()
                if not line:
                    line = ""
                lines.append(line)
    finally:
        return lines


def get_system_includes(lines: list[str]) -> list[re.Match]:
    regexp = re.compile(r"[\t| ]*#[\t| ]*include[\t| ]+<(.+?)>")
    matches = [re.match(regexp, x) for x in lines if re.match(regexp, x)]
    return matches


def get_local_includes(lines: list[str]) -> list[re.Match]:
    regexp = re.compile(r"[\t| ]*#[\t| ]*include[\t| ]+\"(.+?)\"")
    matches = [re.match(regexp, x) for x in lines if re.match(regexp, x)]
    return matches


def get_ifdef(lines: list[str]) -> list[re.Match]:
    regexp = re.compile(r"[\t| ]*#[\t| ]*ifdef[\t| ]+(.*)")
    matches = [re.match(regexp, x) for x in lines if re.match(regexp, x)]
    return matches


def get_ifndef(lines: list[str]) -> list[re.Match]:
    regexp = re.compile(r"[\t| ]*#[\t| ]*ifndef[\t| ]+(.*)")
    matches = [re.match(regexp, x) for x in lines if re.match(regexp, x)]
    return matches

def main() -> None:
    argv = sys.argv
    argc = len(sys.argv)

    if argc < 2:
        print(f"cppnames.py files")
        exit(1)

    files = [Path(x) for x in argv[1:] if Path(x).is_file()]
    for file in files:
        lines = read_lines(file)
        includes = get_system_includes(lines) + get_local_includes(lines)
        if includes:
            print("\n".join([x.group() for x in includes]))


if __name__ == '__main__':
    main()
