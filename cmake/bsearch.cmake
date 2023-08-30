
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)

check_symbol_exists(bsearch "stdlib.h" HAVE_BSEARCH)

set(LIBCFUNK_DECLARE_BSEARCH 1)

if (NOT HAVE_BSEARCH)
  set(HAVE_BSEARCH 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/bsearch.c
  )
endif ()
