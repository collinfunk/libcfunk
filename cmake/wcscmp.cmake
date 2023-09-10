
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcscmp "wchar.h" HAVE_WCSCMP)
else ()
  set(HAVE_WCSCMP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSCMP "1" CACHE INTERNAL "")

if (NOT HAVE_WCSCMP)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/wcscmp.c
  )
endif ()
