
include_guard(GLOBAL)

include(GNUInstallDirs)
include(CheckSymbolExists)
include(CheckFunctionExists)
include(CheckLibraryExists)
include(CheckStructHasMember)
include(CheckTypeSize)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckCSourceCompiles)
include(CheckCSourceRuns)

# These set the following variables if the programs are installed. May be
# useful for running tests and such.
# CVS_EXECUTABLE
# GIT_EXECUTABLE
# Python3_EXECUTABLE
# PERL_EXECUTABLE
# CCACHE_EXECUTABLE
find_package(Git)
find_package(CVS)
find_package(Python3 COMPONENTS Interpreter)
find_package(Perl)
find_program(CCACHE_EXECUTABLE "ccache")

# These variables should be set before including this file. They can be
# defined in a CMakeLists.txt or as a command line option.
set(LIBCFUNK_LIBRARY_NAME "" CACHE STRING "")
set(LIBCFUNK_SOURCE_DIR "" CACHE STRING "")
set(LIBCFUNK_TEST_SOURCE_DIR "" CACHE STRING "")
set(LIBCFUNK_BUILD_DIR "" CACHE STRING "")
set(LIBCFUNK_TEST_BUILD_DIR "" CACHE STRING "")
set(LIBCFUNK_MODULE_DIR "" CACHE STRING "")
set(LIBCFUNK_CONFIG_DIR "" CACHE STRING "")

# Variables for controlling build.
# LIBCFUNK_BUILD_SHARED: Build a shared libary instead of static.
# LIBCFUNK_ENABLE_TESTS: Build test programs for use with CTest.
# LIBCFUNK_USE_CCACHE: Use ccache to speed up build if found.
set(LIBCFUNK_BUILD_SHARED OFF CACHE BOOL "")
set(LIBCFUNK_ENABLE_TESTS ON CACHE BOOL "")
set(LIBCFUNK_USE_CCACHE ON CACHE BOOL "")

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

# Default to 'Debug' builds. Typically this just enables debug symbols.
if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "" FORCE)
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
  if (CVS_EXECUTABLE)
    set(CTEST_CVS_COMMAND "${CVS_EXECUTABLE}" CACHE STRING "")
  endif ()
  if (GIT_EXECUTABLE)
    set(CTEST_GIT_COMMAND "${GIT_EXECUTABLE}" CACHE STRING "")
  endif ()
  include(CTest)
  enable_testing()
endif ()

if ($CACHE{LIBCFUNK_USE_CCACHE} AND CCACHE_EXECUTABLE)
  set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_EXECUTABLE}" CACHE STRING "")
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

list(APPEND CMAKE_REQUIRED_DEFINITIONS "-DWIN32_LEAN_AND_MEAN=1")
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

# Check for some headers.
check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("features.h" HAVE_FEATURES_H)
check_include_file("assert.h" HAVE_ASSERT_H)
check_include_file("stdbool.h" HAVE_STDBOOL_H)

# Check for the size of basic C types.
check_type_size("char" SIZEOF_CHAR)
check_type_size("short" SIZEOF_SHORT)
check_type_size("int" SIZEOF_INT)
check_type_size("long" SIZEOF_LONG)
check_type_size("long long" SIZEOF_LONG_LONG)

# Make sure the host is two's complement.
check_c_source_compiles("
int
main(void)
{
  int verify_twos_complement[(-1 & 3) == 3 ? 1 : -1];
  return 0;
}
" IS_TWOS_COMPLEMENT)

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
  return 0;
}
" CHAR_IS_8_BITS)

if (NOT CHAR_IS_8_BITS)
  message(FATAL_ERROR "This library assumes that `char' is 8-bits wide. \
This is required by the POSIX standard.")
endif ()

# Check int is 32 bits or greater.
if ("${SIZEOF_INT}" STREQUAL "" OR "${SIZEOF_INT}" LESS "4")
  if ("${SIZEOF_INT}" STREQUAL "")
    set(SIZEOF_INT "0")
  endif ()
  math(EXPR BITWIDTH_INT "8 * ${SIZEOF_INT}" OUTPUT_FORMAT DECIMAL)
  message(FATAL_ERROR "This library assumes that `int' is 32-bits or wider. \
On your system `int' is ${BITWIDTH_INT} bits.")
  unset(BITWIDTH_INT)
endif ()

# Check that long long is 64 bits or greater.
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

# Check for the C23 'bool', 'true', and 'false' keywords.
check_c_source_compiles("
int
main (void)
{
  bool value;
  int verify_true[(true == 1) ? 1 : -1];
  int verify_false[(false == 0) ? 1 : -1];
  return 0;
}
" HAVE_C23_BOOL)

# Check for the C99 '_Bool' keyword.
check_c_source_compiles("
int
main (void)
{
  _Bool a = 1;
  _Bool b = 0;
  return 0;
}
" HAVE_C99_BOOL)

# Check for C23 static_assert.
check_c_source_compiles("
int
main (void)
{
  static_assert (5 * 5 == 25, \"Checking for C23 static assert.\");
  static_assert (5 * 5 == 25);
  return 0;
}
" HAVE_C23_STATIC_ASSERT)

# Check for C11 _Static_assert.
check_c_source_compiles("
int
main (void)
{
  _Static_assert (5 * 5 == 25, \"Checking for C11 static assert.\");
  _Static_assert (5 * 5 == 25);
  return 0;
}
" HAVE_C11_STATIC_ASSERT)

# Check for C11 _Noreturn.
check_c_source_compiles("
#include <stdlib.h>

_Noreturn void exit_program (void);

int
main (void)
{
  exit_program ();
}

_Noreturn void
exit_program (void)
{
  exit (0);
}
" HAVE_C11__NORETURN)
