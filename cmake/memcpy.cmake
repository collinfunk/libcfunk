
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(memcpy "string.h" HAVE_MEMCPY)

set(LIBCFUNK_DECLARE_MEMCPY 1)

if (NOT HAVE_MEMCPY)
  libcfunk_add_sources("memcpy.c")
endif ()
