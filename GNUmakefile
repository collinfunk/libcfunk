
# Use ninja since it is faster
CMAKE ?= $(shell command -v cmake)
CMAKE_GENERATOR ?= "Ninja"
BUILD_TOOL ?= $(shell command -v ninja)
BUILD_DIR ?= ./build

.SUFFIXES:
.PHONY: all build-all init clean clean-all

all: build-all

build-all: init
	$(CMAKE) --build $(BUILD_DIR)

init: $(BUILD_DIR)

$(BUILD_DIR):
	$(CMAKE) -S . -B $(BUILD_DIR) -G $(CMAKE_GENERATOR)

clean:
	$(CMAKE) --build $(BUILD_DIR) -t clean

clean-all:
	rm -rf $(BUILD_DIR)
