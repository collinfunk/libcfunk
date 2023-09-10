
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcslen "wchar.h" HAVE_WCSLEN)
else ()
  set(HAVE_WCSLEN "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSLEN "1" CACHE INTERNAL "")

if (NOT HAVE_WCSLEN)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/wcslen.c
  )
endif ()
