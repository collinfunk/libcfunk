
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("mkstemp" "stdlib.h" HAVE_MKSTEMP)
endif ()

set(LIBCFUNK_DECLARE_MKSTEMP "1" CACHE INTERNAL "")

# Substitution function uses getrandom to make a random filename.
if (NOT HAVE_MKSTEMP)
  include($CACHE{LIBCFUNK_MODULE_DIR}/getrandom.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mkstemp.c
  )
endif ()

