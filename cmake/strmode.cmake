
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strmode "string.h" HAVE_STRMODE)

set(LIBCFUNK_DECLARE_STRMODE 1)

if (NOT HAVE_STRMODE)
  libcfunk_add_sources("strmode.c")
endif ()

