
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(memset "string.h" HAVE_MEMSET)

set(LIBCFUNK_DECLARE_MEMSET 1)

if (NOT HAVE_MEMSET)
  libcfunk_add_sources("memset.c")
endif ()
