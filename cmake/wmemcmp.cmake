
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wmemcmp "wchar.h" HAVE_WMEMCMP)
else ()
  set(HAVE_WMEMCMP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WMEMCMP "1" CACHE INTERNAL "")

if (NOT HAVE_WMEMCMP)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/wmemcmp.c
  )
endif ()
