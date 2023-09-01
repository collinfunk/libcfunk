
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strncpy "string.h" HAVE_STRNCPY)

set(LIBCFUNK_DECLARE_STRNCPY 1)

if (NOT HAVE_STRNCPY)
  libcfunk_add_sources("strncpy.c")
endif ()
