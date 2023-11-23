
# Use ninja since it is faster
CMAKE ?= $(shell command -v cmake)
CMAKE_GENERATOR ?= $(shell command -v ninja >/dev/null 2>&1 && echo "Ninja" \
  || echo "Unix Makefiles")
BUILD_DIR ?= ./build

# Compilers for testing
CC = $(shell command -v cc)
# CC = gcc
# CC = clang
# CC = tcc
# CC = pcc

.SUFFIXES:
.PHONY: all build-all init init-mingw clean clean-all check

all: build-all

build-all: init
	$(CMAKE) --build $(BUILD_DIR)

init: $(BUILD_DIR)

# Configure twice since sometimes headers don't generate the first time.
init-mingw:
	if test -d $(BUILD_DIR); then \
	  rm -r $(BUILD_DIR); \
	fi;
	$(CMAKE) -S . -B $(BUILD_DIR) -G $(CMAKE_GENERATOR) \
	  -DCMAKE_TOOLCHAIN_FILE=./cmake/x86_64-w64-mingw32.cmake
	$(CMAKE) -S . -B build

# Configure twice since sometimes headers don't generate the first time.
$(BUILD_DIR):
	$(CMAKE) -S . -B $(BUILD_DIR) -G $(CMAKE_GENERATOR) \
	  -DCMAKE_C_COMPILER=$(CC)
	$(CMAKE) -S . -B build

clean:
	$(CMAKE) --build $(BUILD_DIR) -t clean

check:
	cd $(BUILD_DIR) && ctest -j 4

clean-all:
	rm -rf $(BUILD_DIR)
