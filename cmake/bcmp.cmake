
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_c_symbol("bcmp" "strings.h")

set(LIBCFUNK_DECLARE_BCMP "1" CACHE INTERNAL "")

if (NOT HAVE_BCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/bcmp.c
  )
endif ()

