
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)

libcfunk_check_symbol_exists(bsearch "stdlib.h" HAVE_BSEARCH)

set(LIBCFUNK_DECLARE_BSEARCH 1)

if (NOT HAVE_BSEARCH)
  libcfunk_add_sources("bsearch.c")
endif ()
