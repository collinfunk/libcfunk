
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(memcmp "string.h" HAVE_MEMCMP)

set(LIBCFUNK_DECLARE_MEMCMP 1)

if (NOT HAVE_MEMCMP)
  libcfunk_add_sources("memcmp.c")
endif ()
