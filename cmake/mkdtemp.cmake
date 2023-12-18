
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/mkdir.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("mkdtemp" "stdlib.h" HAVE_MKDTEMP)
endif ()

set(LIBCFUNK_DECLARE_MKDTEMP "1" CACHE STRING "")

# Substitution function uses getrandom to make a random filename.
if (NOT HAVE_MKDTEMP)
  include($CACHE{LIBCFUNK_MODULE_DIR}/getrandom.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mkdtemp.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-mkdtemp.cmake)
endif ()

