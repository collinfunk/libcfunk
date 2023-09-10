
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcscpy "wchar.h" HAVE_WCSCPY)
else ()
  set(HAVE_WCSCPY "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSCPY "1" CACHE INTERNAL "")

if (NOT HAVE_WCSCPY)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/wcscpy.c
  )
endif ()
