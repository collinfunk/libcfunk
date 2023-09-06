
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtoull" "stdlib.h" HAVE_STRTOULL)
else ()
  set (HAVE_STRTOULL "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_STRTOULL "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOULL)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strtoull.c
  )
endif ()

