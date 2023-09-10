
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcsnlen "wchar.h" HAVE_WCSNLEN)
else ()
  set(HAVE_WCSNLEN "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSNLEN "1" CACHE INTERNAL "")

if (NOT HAVE_WCSNLEN)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/wcsnlen.c
  )
endif ()
