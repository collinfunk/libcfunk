
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(memchr "string.h" HAVE_MEMCHR)

set(LIBCFUNK_DECLARE_MEMCHR 1)

if (NOT HAVE_MEMCHR)
  libcfunk_add_sources("memchr.c")
endif ()
