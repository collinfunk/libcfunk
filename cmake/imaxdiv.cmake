
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/inttypes-h.cmake)

if (HAVE_INTTYPES_H)
  check_symbol_exists("imaxdiv" "inttypes.h" HAVE_IMAXDIV)
endif ()

set(LIBCFUNK_DECLARE_IMAXDIV "1" CACHE STRING "")

if (NOT HAVE_IMAXDIV)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/imaxdiv.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-imaxdiv.cmake)
endif ()
