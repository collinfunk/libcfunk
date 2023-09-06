
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtol" "stdlib.h" HAVE_STRTOL)
else ()
  set (HAVE_STRTOL "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_STRTOL "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOL)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strtol.c
  )
endif ()

