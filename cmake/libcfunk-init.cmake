
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

# Make sure the host is two's complement.
check_c_source_compiles("
int
main(void)
{
#if -1 & 3 == 1
  10000001 & 00000011 == 1
  sign-magnitude is unsupported.
#elif -1 & 3 == 2
  11111110 & 00000011 == 2
  one's complement is unsupported.
#elif -1 & 3 == 3
  /* 01111111 & 00000011 == 3 */
  return 0;
#else
  Unknown signed number representation.
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
