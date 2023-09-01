
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strcasecmp "string.h" HAVE_STRCASECMP)

set(LIBCFUNK_DECLARE_STRCASECMP 1)

if (NOT HAVE_STRCASECMP)
  libcfunk_add_sources("strcasecmp.c")
endif ()
