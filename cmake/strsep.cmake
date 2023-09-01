
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(strsep "string.h" HAVE_STRSEP)

set(LIBCFUNK_DECLARE_STRSEP 1)

if (NOT HAVE_STRSEP)
  libcfunk_add_sources("strsep.c")
endif ()

