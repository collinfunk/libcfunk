
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wmemcpy "wchar.h" HAVE_WMEMCPY)
else ()
  set(HAVE_WMEMCPY "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WMEMCPY "1" CACHE INTERNAL "")

if (NOT HAVE_WMEMCPY)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/wmemcpy.c
  )
endif ()
