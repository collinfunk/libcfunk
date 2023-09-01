
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/unistd.cmake)

libcfunk_check_symbol_exists(swab "unistd.h" HAVE_SWAB)

set(LIBCFUNK_DECLARE_SWAB 1)

if (NOT HAVE_SWAB)
  libcfunk_add_sources("swab.c")
endif ()
