
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strncasecmp "string.h" HAVE_STRNCASECMP)

set(LIBCFUNK_DECLARE_STRNCASECMP 1)

if (NOT HAVE_STRNCASECMP)
  libcfunk_add_sources("strncasecmp.c")
endif ()
