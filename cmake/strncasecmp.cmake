
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("strncasecmp" "strings.h" HAVE_STRNCASECMP)
else ()
  set (HAVE_STRNCASECMP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_STRNCASECMP "1" CACHE INTERNAL "")

if (NOT HAVE_STRNCASECMP)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strncasecmp.c
  )
endif ()

