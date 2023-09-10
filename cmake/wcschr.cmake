
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcschr "wchar.h" HAVE_WCSCHR)
else ()
  set(HAVE_WCSCHR "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSCHR "1" CACHE INTERNAL "")

if (NOT HAVE_WCSCHR)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/wcschr.c
  )
endif ()
