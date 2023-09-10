
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcpcpy "wchar.h" HAVE_WCPCPY)
else ()
  set(HAVE_WCPCPY "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCPCPY "1" CACHE INTERNAL "")

if (NOT HAVE_WCPCPY)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/wcpcpy.c
  )
endif ()
