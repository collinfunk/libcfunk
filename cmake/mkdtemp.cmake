
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)
include(${LIBCFUNK_MODULE_DIR}/getrandom.cmake)

libcfunk_check_symbol_exists(mkdtemp "stdlib.h" HAVE_MKDTEMP)

set(LIBCFUNK_DECLARE_MKDTEMP 1)

if (NOT HAVE_MKDTEMP)
  libcfunk_add_sources("mkdtemp.c")
endif ()
