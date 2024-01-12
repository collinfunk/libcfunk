
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_include_file("stdlib.h" HAVE_STDLIB_H)
if (HAVE_UNISTD_H OR HAVE_STDLIB_H)
  set(SWAB_INCLUDES "")
  if (HAVE_UNISTD_H)
    list(APPEND SWAB_INCLUDES "unistd.h")
  endif ()
  if (HAVE_STDLIB_H)
    list(APPEND SWAB_INCLUDES "stdlib.h")
  endif ()
  check_symbol_exists("swab" "${SWAB_INCLUDES}" HAVE_SWAB)
  unset(SWAB_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_SWAB "1" CACHE STRING "")

if (NOT HAVE_SWAB OR LIBCFUNK_REPLACE_SWAB)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/swab.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-swab.cmake)
endif ()

