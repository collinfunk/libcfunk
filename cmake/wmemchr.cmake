
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wmemchr "wchar.h" HAVE_WMEMCHR)
else ()
  set(HAVE_WMEMCHR "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WMEMCHR "1" CACHE INTERNAL "")

if (NOT HAVE_WMEMCHR)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/wmemchr.c
  )
endif ()
