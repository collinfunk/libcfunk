
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strchr "string.h" HAVE_STRCHR)

set(LIBCFUNK_DECLARE_STRCHR 1)

if (NOT HAVE_STRCHR)
  libcfunk_add_sources("strchr.c")
endif ()
