
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("iscntrl" "ctype.h" HAVE_ISCNTRL)
endif ()

set(LIBCFUNK_DECLARE_ISCNTRL "1" CACHE INTERNAL "")

if (NOT HAVE_ISCNTRL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iscntrl.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

