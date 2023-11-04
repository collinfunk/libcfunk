
include_guard(GLOBAL)

include(CheckSymbolExists)
include(CheckFunctionExists)
include(CheckStructHasMember)
include(CheckTypeSize)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckCSourceCompiles)
include(CheckCSourceRuns)

# These variables should be set before including this file. They can be
# defined in a CMakeLists.txt or as a command line option.
set(LIBCFUNK_LIBRARY_NAME "" CACHE STRING "")
set(LIBCFUNK_SOURCE_DIR "" CACHE STRING "")
set(LIBCFUNK_TEST_SOURCE_DIR "" CACHE STRING "")
set(LIBCFUNK_BUILD_DIR "" CACHE STRING "")
set(LIBCFUNK_TEST_BUILD_DIR "" CACHE STRING "")
set(LIBCFUNK_MODULE_DIR "" CACHE STRING "")
set(LIBCFUNK_CONFIG_DIR "" CACHE STRING "")

set(LIBCFUNK_BUILD_SHARED OFF CACHE BOOL "")
set(LIBCFUNK_ENABLE_TESTS ON CACHE BOOL "")

if ("$CACHE{LIBCFUNK_LIBRARY_NAME}" STREQUAL "")
  message(FATAL_ERROR "Set LIBCFUNK_LIBRARY_NAME as a cache variable before "
    "including libcfunk-init.cmake. This is the name that the library is "
    "linked as without the 'lib' prefix and file extension.")
endif ()

if ("$CACHE{LIBCFUNK_SOURCE_DIR}" STREQUAL "")
  message(FATAL_ERROR "Set LIBCFUNK_SOURCE_DIR as a cache variable before "
    "include libcfunk-init.cmake. This is the directory containing all "
    "library sources used.")
endif ()

if ("$CACHE{LIBCFUNK_TEST_SOURCE_DIR}" STREQUAL "")
  message(FATAL_ERROR "Set LIBCFUNK_TEST_SOURCE_DIR as a cache variable "
    "before including libcfunk-init.cmake. This is the directory with all "
    "sources for test executables.")
endif ()

if ("$CACHE{LIBCFUNK_BUILD_DIR}" STREQUAL "")
  message(FATAL_ERROR "Set LIBCFUNK_BUILD_DIR as a cache variable before "
    "including libcfunk-init.cmake. This is the directory where all library "
    "objects are compiled and linked.")
endif ()

if ("$CACHE{LIBCFUNK_TEST_BUILD_DIR}" STREQUAL "")
  message(FATAL_ERROR "Set LIBCFUNK_TEST_BUILD_DIR as a cache variable before "
    "including libcfunk-init.cmake. This is the directory where all test "
    "executables are placed.")
endif ()

if ("$CACHE{LIBCFUNK_MODULE_DIR}" STREQUAL "")
  message(FATAL_ERROR "Set LIBCFUNK_MODULE_DIR as a cache variable before "
    "including libcfunk-init.cmake. This directory is where all *.cmake files "
    "are located. This variable is used internally to include dependent "
    "modules.")
endif ()

if ("$CACHE{LIBCFUNK_CONFIG_DIR}" STREQUAL "")
  message(FATAL_ERROR "Set LIBCFUNK_CONFIG_DIR as a cache variable before "
    "including libcfunk-init.cmake. This directory is where all generated "
    "headers are placed.")
endif ()

# Make sure the configuration directory exists before we try anything.
file(MAKE_DIRECTORY $CACHE{LIBCFUNK_CONFIG_DIR})

# Build shared library if requested.
if ($CACHE{LIBCFUNK_BUILD_SHARED})
  add_library("$CACHE{LIBCFUNK_LIBRARY_NAME}" SHARED)
else ()
  add_library("$CACHE{LIBCFUNK_LIBRARY_NAME}" STATIC)
endif ()

if ($CACHE{LIBCFUNK_ENABLE_TESTS})
  include(CTest)
  enable_testing()
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

list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_ALL_SOURCE=1")
list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_DARWIN_C_SOURCE=1")
list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_FILE_OFFSET_BITS=64")
list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_GNU_SOURCE=1")
list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_LARGE_FILES=1")
list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_LARGEFILE_SOURCE=1")
list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_NETBSD_SOURCE=1")
list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D__STDC_WANT_IEC_60559_BFP_EXT__=1")
list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D__STDC_WANT_IEC_60559_FUNCS_EXT__=1")
list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D__STDC_WANT_IEC_60559_TYPES_EXT__=1")
list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D__STDC_WANT_LIB_EXT2__=1")
list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_TIME_BITS=64")

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("features.h" HAVE_FEATURES_H)

# Make sure the host is two's complement.
check_c_source_compiles("
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
check_c_source_compiles("
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
check_type_size("int" SIZEOF_INT)
check_type_size("long long" SIZEOF_LONG_LONG)

# Check int is 32-bits.
if ("${SIZEOF_INT}" STREQUAL "" OR "${SIZEOF_INT}" LESS "4")
  if ("${SIZEOF_INT}" STREQUAL "")
    set(SIZEOF_INT "0")
  endif ()
  math(EXPR BITWIDTH_INT "8 * ${SIZEOF_INT}" OUTPUT_FORMAT DECIMAL)
  message(FATAL_ERROR "This library assumes that `int' is 32-bits or wider. \
On your system `int' is ${BITWIDTH_INT} bits.")
  unset(BITWIDTH_INT)
endif ()

if ("${SIZEOF_LONG_LONG}" STREQUAL "" OR "${SIZEOF_LONG_LONG}" LESS "8")
  if ("${SIZEOF_LONG_LONG}" STREQUAL "")
    set(SIZEOF_LONG_LONG "0")
  endif ()
  math(EXPR BITWIDTH_LONG_LONG "8 * ${SIZEOF_LONG_LONG}" OUTPUT_FORMAT DECIMAL)
  message(FATAL_ERROR "This library assumes that `long long' is 64-bits or \
wider. On your system `long long' is ${BITWIDTH_LONG_LONG} bits.")
  unset(BITWIDTH_LONG_LONG)
endif ()

check_c_source_compiles("

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
