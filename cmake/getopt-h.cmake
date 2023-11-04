
include_guard(GLOBAL)

# Generate <getopt.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_GETOPT_H "1" CACHE STRING "")

check_include_file("getopt.h" HAVE_GETOPT_H)
check_include_file("stdlib.h" HAVE_STDLIB_H)
check_include_file("unistd.h" HAVE_UNISTD_H)

if (HAVE_GETOPT_H OR HAVE_STDLIB_H OR HAVE_UNISTD_H)
  set(GETOPT_INCLUDES "")
  if (HAVE_STDLIB_H)
    list(APPEND GETOPT_INCLUDES "stdlib.h")
  endif ()
  if (HAVE_UNISTD_H)
    list(APPEND GETOPT_INCLUDES "unistd.h")
  endif ()
  if (HAVE_GETOPT_H)
    list(APPEND GETOPT_INCLUDES "getopt.h")
  endif ()
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "${GETOPT_INCLUDES}")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct option" STRUCT_OPTION)
  check_symbol_exists("optarg" "${GETOPT_INCLUDES}" HAVE_OPTARG)
  check_symbol_exists("opterr" "${GETOPT_INCLUDES}" HAVE_OPTERR)
  check_symbol_exists("optind" "${GETOPT_INCLUDES}" HAVE_OPTIND)
  check_symbol_exists("optopt" "${GETOPT_INCLUDES}" HAVE_OPTOPT)
  unset(GETOPT_INCLUDES)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getopt-h.cmake)
endif ()

