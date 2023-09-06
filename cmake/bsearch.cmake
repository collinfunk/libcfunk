
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("bsearch" "stdlib.h" HAVE_BSEARCH)
else ()
  set (HAVE_BSEARCH "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_BSEARCH "1" CACHE INTERNAL "")

if (NOT HAVE_BSEARCH)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/bsearch.c
  )
endif ()

