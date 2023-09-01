
include_guard(GLOBAL)

# Includes to check for system information.
include(CheckSymbolExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckTypeSize)
include(CheckCSourceCompiles)

# Cache variables which control where the library is built at.
set(LIBCFUNK_LIBRARY_NAME "cfunk" CACHE STRING "The name of the library \
that is built, excluding the lib prefix.")

set(LIBCFUNK_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/lib" CACHE STRING
"The directory containing all source files for the library.")

set (LIBCFUNK_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/lib" CACHE STRING
"The directory where the library file is stored when built.")

set(LIBCFUNK_TEST_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/tests" CACHE STRING
"The directory containing all test source files.")

set(LIBCFUNK_TEST_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/tests" CACHE STRING
"The directory where all test executables are stored when built.")

set(LIBCFUNK_MODULE_DIR "${CMAKE_CURRENT_LIST_DIR}/cmake" CACHE STRING
"The directory where all .cmake files containing build instructions \
are located.")

if (NOT DEFINED LIBCFUNK_LIBRARY_NAME)
  message (FATAL_ERROR "LIBCFUNK_LIBRARY_NAME is not set.")
endif ()

if (NOT DEFINED LIBCFUNK_SOURCE_DIR)
  message (FATAL_ERROR "LIBCFUNK_SOURCE_DIR is not set.")
endif ()

if (NOT DEFINED LIBCFUNK_TEST_SOURCE_DIR)
  message (FATAL_ERROR "LIBCFUNK_TEST_SOURCE_DIR is not set.")
endif ()

if (NOT DEFINED LIBCFUNK_TEST_BUILD_DIR)
  message (FATAL_ERROR "LIBCFUNK_TEST_BUILD_DIR is not set.")
endif ()

if (NOT DEFINED LIBCFUNK_BUILD_DIR)
  message (FATAL_ERROR "LIBCFUNK_BUILD_DIR is not set.")
endif ()

if (NOT DEFINED LIBCFUNK_MODULE_DIR)
  message (FATAL_ERROR "LIBCFUNK_MODULE_DIR is not set.")
endif ()

# Options
option(LIBCFUNK_BUILD_TESTS "Build test executables" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# System header replacements rely on #include_next.
check_c_source_compiles("
#include_next <stdlib.h>

int
main (void)
{
  return 0;
}"
HAVE_INCLUDE_NEXT_DIRECTIVE)

# Required by system header templates.
if (NOT HAVE_INCLUDE_NEXT_DIRECTIVE)
  message (FATAL_ERROR "Your compiler does not support #include_next.")
endif ()

# check_include_file () except that if HEADER is not found, VAR is set to 0.
# This allows it to be used in @VAR@ substitution in configure files.
macro (libcfunk_check_include_file header var)
  check_include_file("${header}" ${var})
  if (NOT ${var})
    set(${var} 0)
  endif ()
endmacro ()

# For lists of headers.
macro (libcfunk_check_include_files headers var)
  check_include_files("${headers}" ${var})
  if (NOT ${var})
    set(${var} 0)
  endif ()
endmacro ()

# check_symbol_exists () except that if SYMBOL is not found, VAR is set to 0.
# This allows it to be used in @VAR@ substitution in configure files.
macro (libcfunk_check_symbol_exists symbol header var)
  check_symbol_exists(${symbol} "${header}" ${var})
  if (NOT ${var})
    set(${var} 0)
  endif ()
endmacro ()

# Adds a source file or list of source file to the library.
# All function names are relative to LIBCFUNK_SOURCE_DIR
macro (libcfunk_add_sources file_names)
  foreach (file_name ${file_names})
    if (NOT EXISTS ${LIBCFUNK_SOURCE_DIR}/${file_name})
      message(FATAL_ERROR "Tried to add source file that does not exist: ${LIBCFUNK_SOURCE_DIR}/${file_name}")
    else ()
      target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE ${LIBCFUNK_SOURCE_DIR}/${file_name})
    endif ()
  endforeach()
endmacro ()

libcfunk_check_include_file("sys/types.h" HAVE_SYS_TYPES_H)
libcfunk_check_include_file("windows.h" HAVE_WINDOWS_H)

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
set(LIBCFUNK_GENERATE_ERROR_H FALSE)
