
include_guard(GLOBAL)

include(CheckSymbolExists)
include(CheckFunctionExists)
include(CheckStructHasMember)
include(CheckTypeSize)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckCSourceCompiles)
include(CheckCSourceRuns)

# Cache variables for directories
set(LIBCFUNK_LIBRARY_NAME "cfunk" CACHE STRING
  "The name of the library to build.")
set(LIBCFUNK_SOURCE_DIR "${CMAKE_SOURCE_DIR}/lib" CACHE STRING
  "The directory containing all library sources.")
set(LIBCFUNK_TEST_SOURCE_DIR "${CMAKE_SOURCE_DIR}/tests" CACHE STRING
  "The directory containing all test sources.")
set(LIBCFUNK_BUILD_DIR "${CMAKE_BINARY_DIR}" CACHE STRING
  "The path where all compiled objects and libraries are built.")
set(LIBCFUNK_TEST_BUILD_DIR "${CMAKE_BINARY_DIR}/tests" CACHE STRING
  "The path where all test executables go.")
set(LIBCFUNK_MODULE_DIR "${CMAKE_SOURCE_DIR}/cmake" CACHE STRING
  "The directory containing all *.cmake files which are used for including
dependent modules.")
set(LIBCFUNK_CONFIG_DIR "${CMAKE_BINARY_DIR}/compat" CACHE STRING
  "The directory containing all generated files and headers used for building
the library.")
set(LIBCFUNK_SCRIPT_DIR "${CMAKE_SOURCE_DIR}/scripts" CACHE STRING
  "The directory containing all helper scripts.")
set(LIBCFUNK_BUILD_SHARED OFF CACHE BOOL
  "This library should typically be built as a static library where you
include what your program needs. Setting this to true will build a shared
library anyways.")

# Enable testing by default.
set(LIBCFUNK_ENABLE_TESTS ON CACHE BOOL "Build test executables.")

# Try to give a useful warning if LIBCFUNK_MODULE_DIR is set incorrectly.
if (NOT EXISTS $CACHE{LIBCFUNK_MODULE_DIR}/libcfunk-init.cmake)
  message(FATAL_ERROR "Could not find `libcfunk-init.cmake' in \
LIBCFUNK_MODULE_DIR. Make sure you set the paths correctly.")
endif ()

# Make sure the configuration directory exists before we try anything.
file(MAKE_DIRECTORY $CACHE{LIBCFUNK_CONFIG_DIR})

file(APPEND $CACHE{LIBCFUNK_CONFIG_DIR}/config.h.cmake "
#ifndef CONFIG_H
#define CONFIG_H

/* TODO: Move these. */
#ifndef _ALL_SOURCE
#  define _ALL_SOURCE 1
#endif

#ifndef _GNU_SOURCE
#  define _GNU_SOURCE 1
#endif

#ifndef __STDC_WANT_LIB_EXT2__
#  define __STDC_WANT_LIB_EXT2__ 1
#endif

#ifndef __STDC_WANT_IEC_60559_BFP_EXT__
#  define __STDC_WANT_IEC_60559_BFP_EXT__ 1
#endif

")

# Build shared library if requested.
if ($CACHE{LIBCFUNK_BUILD_SHARED})
  add_library("$CACHE{LIBCFUNK_LIBRARY_NAME}" SHARED)
else ()
  add_library("$CACHE{LIBCFUNK_LIBRARY_NAME}" STATIC)
endif ()

# Set build directory for static and shared library.
set_target_properties("$CACHE{LIBCFUNK_LIBRARY_NAME}" PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY "$CACHE{LIBCFUNK_BUILD_DIR}"
  ARCHIVE_OUTPUT_DIRECTORY "$CACHE{LIBCFUNK_BUILD_DIR}"
)

# Include paths
target_include_directories("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC
  $CACHE{LIBCFUNK_SOURCE_DIR}
  $CACHE{LIBCFUNK_BUILD_DIR}
  $CACHE{LIBCFUNK_CONFIG_DIR}
)

# Add sources used by various different files.
target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/__has_attribute.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/__has_builtin.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/__has_c_attribute.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/__has_cpp_attribute.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/__has_declspec_attribute.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/__has_extension.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/__has_feature.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/__has_include.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/__has_include_next.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/__has_warning.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/__is_identifier.h
)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_GNU_SOURCE")
endif ()

# Internal cache values to signal libcfunk-final needs to create headers.
set(LIBCFUNK_GENERATE_ALLOCA_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_ASSERT_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_CTYPE_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_DIRENT_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_ERR_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_ERROR_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_FCNTL_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_INTTYPES_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_LIMITS_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_MALLOC_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_PTY_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_STDCKDINT_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_STDINT_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_STDIO_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_STDLIB_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_STRING_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_STRINGS_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_SYS_ENDIAN_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_SYS_IOCTL_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_SYS_RANDOM_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_SYS_STAT_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_SYS_TIME_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_SYS_TYPES_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_SYS_WAIT_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_STDBOOL_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_TERMIOS_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_TIME_H "0" CACHE INTERNAL "")
set(LIBCFUNK_GENERATE_UNISTD_H "0" CACHE INTERNAL "")

# check_c_compiles SOURCE_STRING VARIABLE
function (check_c_compiles source_code variable)
  if (NOT DEFINED ${variable})
    check_c_source_compiles("${source_code}" ${variable})
    if (${variable})
      set(${variable} "1" CACHE STRING "" FORCE)
    else ()
      set(${variable} "0" CACHE STRING "" FORCE)
    endif ()
    mark_as_advanced(FORCE ${variable})
    file(APPEND "${LIBCFUNK_CONFIG_DIR}/config.h.cmake"
                "#cmakedefine ${variable} @${variable}@\n\n")
  endif ()
endfunction ()

# check_c_type_exists TYPE_NAME [VAR_NAME]
# Sets HAVE_TYPE_NAME to 1 if the type exists else 0.
# Sets SIZEOF_TYPE_NAME to sizeof (TYPE_NAME) if type exists else 0.
# Sets TYPE_NAME_WIDTH to sizeof (TYPE_NAME) * 8 if type exists else 0.
# If the optional VAR_NAME argument is passed it takes the place of
# TYPE_NAME for definitions.
function (check_c_type_exists type_name)
  if (ARGC GREATER "1")
    set(UPPER_NAME "${ARGV1}")
  else ()
    string(TOUPPER "${type_name}" UPPER_NAME)
    string(REPLACE " " "_" UPPER_NAME "${UPPER_NAME}")
  endif ()
  string(REPLACE "HAVE_" "" UPPER_NAME "${UPPER_NAME}")
  set(HAVE_VAR "HAVE_${UPPER_NAME}")
  set(SIZEOF_VAR "SIZEOF_${UPPER_NAME}")
  set(WIDTH_VAR "${UPPER_NAME}_WIDTH")
  if (NOT DEFINED ${HAVE_VAR})
    check_type_size("${type_name}" ${UPPER_NAME})
    if (${HAVE_VAR})
      set(${HAVE_VAR} "1" CACHE STRING "" FORCE)
      set(${SIZEOF_VAR} "${${UPPER_NAME}}" CACHE STRING "" FORCE)
      math(EXPR ${WIDTH_VAR} "8 * ${${SIZEOF_VAR}}" OUTPUT_FORMAT DECIMAL)
      set(${WIDTH_VAR} "${${WIDTH_VAR}}" CACHE STRING "" FORCE)
    else ()
      set(${HAVE_VAR} "0" CACHE STRING "" FORCE)
      set(${SIZEOF_VAR} "0" CACHE STRING "" FORCE)
      set(${WIDTH_VAR} "0" CACHE STRING "" FORCE)
    endif ()
    mark_as_advanced(FORCE "${HAVE_VAR}")
    mark_as_advanced(FORCE "${SIZEOF_VAR}")
    mark_as_advanced(FORCE "${WIDTH_VAR}")
    file(APPEND "${LIBCFUNK_CONFIG_DIR}/config.h.cmake"
                "#cmakedefine ${HAVE_VAR} @${HAVE_VAR}@\n\n")
    file(APPEND "${LIBCFUNK_CONFIG_DIR}/config.h.cmake"
      "#cmakedefine ${SIZEOF_VAR} @${SIZEOF_VAR}@\n\n")
    # Redefinition
    #file(APPEND "${LIBCFUNK_CONFIG_DIR}/config.h.cmake"
    #            "#cmakedefine ${WIDTH_VAR} @${WIDTH_VAR}@\n\n")
  endif ()
endfunction ()

# check_c_system_headers HEADER_NAME_LIST
# The header names should be put in the same order they should be #included.
# Sets HAVE_HEADER_NAME_H in the cache and only includes found headers.
function (check_c_system_headers header_names)
  set(FOUND_HEADERS "")
  list(REMOVE_DUPLICATES header_names)
  foreach (header IN LISTS header_names)
    string(STRIP "${header}" header)
    string(REGEX REPLACE "[\\/.]" "_" UPPER_NAME "${header}")
    string(TOUPPER "${UPPER_NAME}" UPPER_NAME)
    set(HAVE_VAR "HAVE_${UPPER_NAME}")
    set(PATH_VAR "${UPPER_NAME}_PATH")
    if (DEFINED CACHE{${HAVE_VAR}})
      if (${HAVE_VAR})
        list(APPEND FOUND_HEADERS "${header}")
      endif ()
    else ()
      check_include_files("${FOUND_HEADERS};${header}" ${HAVE_VAR})
      if (${HAVE_VAR})
        list(APPEND FOUND_HEADERS "${header}")
        set(${HAVE_VAR} "1" CACHE STRING "" FORCE)
        find_file(${PATH_VAR} "${header}")
        if (${PATH_VAR})
          set(${PATH_VAR} "${${PATH_VAR}}" CACHE STRING "" FORCE)
        else ()
          set(${PATH_VAR} "" CACHE STRING "" FORCE)
        endif ()
      else ()
        set(${HAVE_VAR} "0" CACHE STRING "" FORCE)
        set(${PATH_VAR} "" CACHE STRING "" FORCE)
      endif ()
      mark_as_advanced(FORCE ${HAVE_VAR})
      mark_as_advanced(FORCE ${PATH_VAR})
      file(APPEND "${LIBCFUNK_CONFIG_DIR}/config.h.cmake"
                   "#cmakedefine ${HAVE_VAR} @${HAVE_VAR}@\n\n")
    endif ()
  endforeach ()
endfunction ()

function (check_c_symbol symbol_name header_names)
  if (ARGC GREATER "2")
    set(SYMBOL_HAVE_VAR "${ARGV2}")
  else ()
    string(TOUPPER "HAVE_${symbol_name}" SYMBOL_HAVE_VAR)
  endif ()
  if (NOT DEFINED CACHE{${SYMBOL_HAVE_VAR}})
    set(FOUND_HEADERS "")
    list(REMOVE_DUPLICATES header_names)
    foreach (header IN LISTS header_names)
      string(STRIP "${header}" header)
      string(REGEX REPLACE "[\\/.]" "_" UPPER_NAME "${header}")
      string(TOUPPER "${UPPER_NAME}" UPPER_NAME)
      set(HEADER_HAVE_VAR "HAVE_${UPPER_NAME}")
      if (DEFINED CACHE{${HEADER_HAVE_VAR}})
        if (${HEADER_HAVE_VAR})
          list(APPEND FOUND_HEADERS "${header}")
        endif ()
      endif ()
    endforeach ()
    check_symbol_exists("${symbol_name}" "${FOUND_HEADERS}" ${SYMBOL_HAVE_VAR})
    if (${SYMBOL_HAVE_VAR})
      set(${SYMBOL_HAVE_VAR} "1" CACHE STRING "" FORCE)
    else ()
      set(${SYMBOL_HAVE_VAR} "0" CACHE STRING "" FORCE)
    endif ()
    mark_as_advanced(FORCE ${SYMBOL_HAVE_VAR})
    file(APPEND "${LIBCFUNK_CONFIG_DIR}/config.h.cmake"
                "#cmakedefine ${SYMBOL_HAVE_VAR} @${SYMBOL_HAVE_VAR}@\n\n")
  endif ()
endfunction ()

function (check_c_function_links function_name)
  if (ARGC GREATER "2")
    set(FUNCTION_HAVE_VAR "${ARGV2}")
  else ()
    string(TOUPPER "HAVE_${function_name}" FUNCTION_HAVE_VAR)
  endif ()
  if (NOT DEFINED CACHE{${FUNCTION_HAVE_VAR}})
    check_function_exists("${function_name}" ${FUNCTION_HAVE_VAR})
    if (${FUNCTION_HAVE_VAR})
      set(${FUNCTION_HAVE_VAR} "1" CACHE STRING "" FORCE) 
    else ()
      set(${FUNCTION_HAVE_VAR} "0" CACHE STRING "" FORCE)
    endif ()
    mark_as_advanced(FORCE ${FUNCTION_HAVE_VAR})
    file(APPEND "${LIBCFUNK_CONFIG_DIR}/config.h.cmake"
                "#cmakedefine ${FUNCTION_HAVE_VAR} @${FUNCTION_HAVE_VAR}@\n\n")
  endif ()
endfunction ()

function (check_c_struct_has_member struct member headers variable)
  if (NOT DEFINED CACHE{${variable}})
    check_struct_has_member("${struct}" "${member}" "${headers}" "${variable}")
    if (${variable})
      set(${variable} "1" CACHE STRING "" FORCE)
    else ()
      set(${variable} "0" CACHE STRING "" FORCE)
    endif ()
    mark_as_advanced(FORCE ${variable})
    file(APPEND "${LIBCFUNK_CONFIG_DIR}/config.h.cmake"
                "#cmakedefine ${variable} @${variable}@\n\n")
  endif ()
endfunction ()

# Make sure the host is two's complement.
check_c_compiles("
int
main(void)
{
#if -1 & 3 == 1
  /* 10000001 & 00000011 == 1 */
  /* sign-magnitude is unsupported. */
  int array[-1];
#elif -1 & 3 == 2
  /* 11111110 & 00000011 == 2 */
  /* one's complement is unsupported. */
  int array[-1];
#elif -1 & 3 == 3
  /* 01111111 & 00000011 == 3 */
  return 0;
#else
  /* Unknown signed number representation. */
  int array[-1];
#endif
}" IS_TWOS_COMPLEMENT)

# Don't build unless manually overridden.
if (NOT IS_TWOS_COMPLEMENT)
  message(FATAL_ERROR "This library assumes two's complement signed integer \
representation. This is required by the POSIX standard.")
endif ()

# Make sure sizeof (TYPE) * 8 equals the number of bits in TYPE.
check_c_compiles("
int
main (void)
{
  int array[1 - 2 * (((unsigned char) -1) != 255)];
  array[0] = 0;
  return array[0];
}" CHAR_IS_8_BITS)

if (NOT CHAR_IS_8_BITS)
  message(FATAL_ERROR "This library assumes that `char' is 8-bits wide. \
This is required by the POSIX standard.")
endif ()

# Make sure `int' is atleast 32-bits and `long long' is atleast 64-bits.
# POSIX requires the minimum value of INT_MAX is 2147483647, or 2^31 - 1.
# The minimum value of LLONG_MAX is 9223372036854775807, or 2^63 - 1.
# C99 requires long long is 64-bits but check anyways since we don't place
# a language standard requirement on the target.
# This check is only valid if char is 8-bits and if signed integers use
# two's complement representation.
check_c_type_exists("int")
check_c_type_exists("long long")

# Check int is 32-bits.
if ("${SIZEOF_INT}" STREQUAL "" OR "${SIZEOF_INT}" LESS "4")
  message(FATAL_ERROR "This library assumes that `int' is 32-bits or wider. \
On your system `int' is ${INT_WIDTH} bits.")
endif ()

if ("${SIZEOF_LONG_LONG}" STREQUAL "" OR "${SIZEOF_LONG_LONG}" LESS "8")
  message(FATAL_ERROR "This library assumes that `long long' is 64-bits or \
wider. On your system `long long' is ${LONG_LONG_WIDTH} bits.")
endif ()

check_c_compiles("

#include_next <stdlib.h>

int
main (void)
{
  return 0;
}
" HAVE_INCLUDE_NEXT)

# FIXME: If include_next isn't supported, it should be possible to use
# find_file and #include the absolute path to the system header.
if (NOT HAVE_INCLUDE_NEXT)
  message(FATAL_ERROR "Substitution headers required support for the \
`#include_next' C preprocessor directive. This is supported by most compilers \
other than MSVC.")
endif ()
