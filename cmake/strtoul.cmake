
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtoul" "stdlib.h" HAVE_STRTOUL)
else ()
  set (HAVE_STRTOUL "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_STRTOUL "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOUL)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strtoul.c
  )
endif ()

