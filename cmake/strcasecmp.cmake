
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("strcasecmp" "strings.h" HAVE_STRCASECMP)
else ()
  set (HAVE_STRCASECMP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_STRCASECMP "1" CACHE INTERNAL "")

if (NOT HAVE_STRCASECMP)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strcasecmp.c
  )
endif ()

