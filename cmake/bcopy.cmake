
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("bcopy" "strings.h" HAVE_BCOPY)
else ()
  set (HAVE_BCOPY "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_BCOPY "1" CACHE INTERNAL "")

if (NOT HAVE_BCOPY)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/bcopy.c
  )
endif ()

