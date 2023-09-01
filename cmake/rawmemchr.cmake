
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(rawmemchr "string.h" HAVE_RAWMEMCHR)

set(LIBCFUNK_DECLARE_RAWMEMCHR 1)

if (NOT HAVE_RAWMEMCHR)
  libcfunk_add_sources("rawmemchr.c")
endif ()
