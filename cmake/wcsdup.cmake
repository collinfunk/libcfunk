
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcsdup "wchar.h" HAVE_WCSDUP)
else ()
  set(HAVE_WCSDUP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSDUP "1" CACHE INTERNAL "")

if (NOT HAVE_WCSDUP)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/wcsdup.c
  )
endif ()
