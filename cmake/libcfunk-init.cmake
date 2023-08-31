
include_guard(GLOBAL)

# Includes to check for system information.
include(CheckSymbolExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckTypeSize)
include(CheckCSourceCompiles)

# The name the library is built as.
if (NOT DEFINED LIBCFUNK_LIBRARY_NAME)
  message (FATAL_ERROR "LIBCFUNK_LIBRARY_NAME is not set")
endif ()

# The directory where all source files are located.
if (NOT DEFINED LIBCFUNK_SOURCE_DIR)
  message (FATAL_ERROR "LIBCFUNK_SOURCE_DIR is not set")
endif ()

# Location where all test source files are located.
if (NOT DEFINED LIBCFUNK_TEST_SOURCE_DIR)
  message (FATAL_ERROR "LIBCFUNK_TEST_SOURCE_DIR is not set")
endif ()

# Location where all test executables are placed.
if (NOT DEFINED LIBCFUNK_TEST_BUILD_DIR)
  message (FATAL_ERROR "LIBCFUNK_TEST_BUILD_DIR is not set")
endif ()

# The location where all generated and compiled files go.
if (NOT DEFINED LIBCFUNK_BUILD_DIR)
  message (FATAL_ERROR "LIBCFUNK_BUILD_DIR is not set")
endif ()

# The directory where all the cmake files are located.
if (NOT DEFINED LIBCFUNK_MODULE_DIR)
  message (FATAL_ERROR "LIBCFUNK_MODULE_DIR is not set")
endif ()

option(LIBCFUNK_BUILD_TESTS "Build test executables" OFF)

include(${LIBCFUNK_MODULE_DIR}/include-next.cmake)

# Required by system header templates.
if (NOT HAVE_INCLUDE_NEXT_DIRECTIVE)
  message (FATAL_ERROR "Your compiler does not support #include_next.")
endif ()

# Define this so we can check for glibc extensions.
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_GNU_SOURCE")
endif ()

add_library(${LIBCFUNK_LIBRARY_NAME})

# Make sure the output directory is set correctly.
set_target_properties(${LIBCFUNK_LIBRARY_NAME} PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${LIBCFUNK_BUILD_DIR}
  ARCHIVE_OUTPUT_DIRECTORY ${LIBCFUNK_BUILD_DIR}
)

# Headers and generated headers
target_include_directories(${LIBCFUNK_LIBRARY_NAME} PUBLIC
  ${LIBCFUNK_SOURCE_DIR}/
  ${LIBCFUNK_BUILD_DIR}/
  ${LIBCFUNK_BUILD_DIR}/compat/
)

set(LIBCFUNK_GENERATE_STRING_H FALSE)
set(LIBCFUNK_GENERATE_STRINGS_H FALSE)
set(LIBCFUNK_GENERATE_STDINT_H FALSE)
set(LIBCFUNK_GENERATE_STDLIB_H FALSE)
set(LIBCFUNK_GENERATE_STDIO_H FALSE)
set(LIBCFUNK_GENERATE_INTTYPES_H FALSE)
set(LIBCFUNK_GENERATE_TIME_H FALSE)
set(LIBCFUNK_GENERATE_SYS_TIME_H FALSE)
set(LIBCFUNK_GENERATE_ERR_H FALSE)
