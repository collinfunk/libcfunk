
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("bcmp" "strings.h" HAVE_BCMP)
else ()
  set (HAVE_BCMP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_BCMP "1" CACHE INTERNAL "")

if (NOT HAVE_BCMP)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/bcmp.c
  )
endif ()

