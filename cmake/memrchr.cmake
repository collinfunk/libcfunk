
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(memrchr "string.h" HAVE_MEMRCHR)

set(LIBCFUNK_DECLARE_MEMRCHR 1)

if (NOT HAVE_MEMRCHR)
  libcfunk_add_sources("memrchr.c")
endif ()
