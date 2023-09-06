#!/usr/bin/env python3

from __future__ import annotations
from pathlib import Path
import sys


class CMakeCacheItem:
    def __init__(self, key: str, entry_type: str, value: str) -> None:
        self.key = key
        self.entry_type = entry_type
        self.value = value

    def __str__(self) -> str:
        return f"{self.key}:{self.entry_type}={self.value}"

    def config_file_str(self) -> str:
        return f"#define {self.key} {self.value}"

    @classmethod
    def from_string(cls, string: str) -> CMakeCacheItem:
        if string.startswith("#") or string.startswith("//"):
            return None
        line = string.split(":")
        if len(line) != 2:
            return None
        if line[1].endswith("="):
            line[1] = line[1].replace("=", "")
            line.append("0")
        else:
            line = [line[0]] + line[1].split("=")
            if len(line) != 3:
                return None
        return CMakeCacheItem(line[0].strip(), line[1].strip(),
                              line[2].strip())


def read_lines(filename: Path) -> list[str]:
    lines = []
    try:
        with open(filename, 'r', encoding='utf-8') as file_handler:
            for line in file_handler:
                lines.append(line.rstrip() if line.rstrip() else "")
    finally:
        return lines


def print_usage(code: int) -> None:
    print("cmake-cache.py [cache file | build directory]")
    if code != 0:
        exit(code)


def main() -> None:
    argv = sys.argv
    argc = len(sys.argv)

    if argc != 2:
        print_usage(1)

    cache = Path(argv[1])
    if cache.is_dir():
        for filename in Path.iterdir(cache):
            if filename.name == "CMakeCache.txt":
                cache = filename
                break
    if not cache.is_file():
        print_usage(1)

    lines = [line for line in read_lines(cache) if line
             and not line.startswith("#") and not line.startswith("//")]

    entries = [CMakeCacheItem.from_string(x) for x in lines if
               CMakeCacheItem.from_string(x)]
    print("\n".join([x.config_file_str() for x in entries
                     if x.key.startswith("HAVE_")]))


if __name__ == '__main__':
    main()
