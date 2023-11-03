
include_guard(GLOBAL)

# Generate <getopt.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_GETOPT_H "1" CACHE INTERNAL "")

check_include_file("getopt.h" HAVE_GETOPT_H)
check_include_file("stdlib.h" HAVE_STDLIB_H)
check_include_file("unistd.h" HAVE_UNISTD_H)

if (HAVE_GETOPT_H OR HAVE_STDLIB_H OR HAVE_UNISTD_H)
  if (HAVE_STDLIB_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "stdlib.h")
    list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  endif ()
  if (HAVE_UNISTD_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "unistd.h")
    list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  endif ()
  if (HAVE_GETOPT_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "getopt.h")
    list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  endif ()
  check_type_size("struct option" STRUCT_OPTION)
else ()
  set(HAVE_STRUCT_OPTION "" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getopt-h.cmake)
endif ()

