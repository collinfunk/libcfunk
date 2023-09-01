
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strncmp "string.h" HAVE_STRNCMP)

set(LIBCFUNK_DECLARE_STRNCMP 1)

if (NOT HAVE_STRNCMP)
  libcfunk_add_sources("strncmp.c")
endif ()
