
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/mkdir.cmake)

check_c_symbol("mkdtemp" "stdlib.h")

set(LIBCFUNK_DECLARE_MKDTEMP "1" CACHE INTERNAL "")

# Substitution function uses getrandom to make a random filename.
if (NOT HAVE_MKDTEMP)
  include($CACHE{LIBCFUNK_MODULE_DIR}/getrandom.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mkdtemp.c
  )
endif ()

