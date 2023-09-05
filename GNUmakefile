
# Use ninja since it is faster
CMAKE ?= $(shell command -v cmake)
CMAKE_GENERATOR ?= $(shell command -v ninja >/dev/null 2>&1 && echo "Ninja" \
  || echo "Unix Makefiles")
BUILD_DIR ?= ./build

# Enable some stuff so the library has sources.
# Use `ccmake' for more options.
CMAKE_ARGS = -DLIBCFUNK_MODULE_READ_FULL:BOOL=ON \
  -DLIBCFUNK_MODULE_WRITE_FULL:BOOL=ON

.SUFFIXES:
.PHONY: all build-all init init-mingw clean clean-all

all: build-all

build-all: init
	$(CMAKE) --build $(BUILD_DIR)

init: $(BUILD_DIR)

init-mingw:
	if test -d $(BUILD_DIR); then \
	  rm -r $(BUILD_DIR); \
	fi;
	$(CMAKE) -S . -B $(BUILD_DIR) -G $(CMAKE_GENERATOR) \
	  -DCMAKE_TOOLCHAIN_FILE=./cmake/x86_64-w64-mingw32.cmake \
	  $(CMAKE_ARGS)

$(BUILD_DIR):
	$(CMAKE) -S . -B $(BUILD_DIR) -G $(CMAKE_GENERATOR) \
	  $(CMAKE_ARGS)

clean:
	$(CMAKE) --build $(BUILD_DIR) -t clean

clean-all:
	rm -rf $(BUILD_DIR)
