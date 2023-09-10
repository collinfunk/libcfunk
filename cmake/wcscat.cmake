
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcscat "wchar.h" HAVE_WCSCAT)
else ()
  set(HAVE_WCSCAT "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSCAT "1" CACHE INTERNAL "")

if (NOT HAVE_WCSCAT)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/wcscat.c
  )
endif ()
