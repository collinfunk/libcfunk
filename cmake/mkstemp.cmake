
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)
include(${LIBCFUNK_MODULE_DIR}/getrandom.cmake)

libcfunk_check_symbol_exists(mkstemp "stdlib.h" HAVE_MKSTEMP)

set(LIBCFUNK_DECLARE_MKSTEMP 1)

if (NOT HAVE_MKSTEMP)
  libcfunk_add_sources("mkstemp.c")
endif ()
