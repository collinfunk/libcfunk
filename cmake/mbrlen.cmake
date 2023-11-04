
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/mbrtowc.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("mbrlen" "wchar.h" HAVE_MBRLEN)
endif ()

set(LIBCFUNK_DECLARE_MBRLEN "1" CACHE INTERNAL "")

if (NOT HAVE_MBRLEN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mbrlen.c
  )
endif ()

