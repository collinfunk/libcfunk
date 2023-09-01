
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)

libcfunk_check_symbol_exists(strtol "stdlib.h" HAVE_STRTOL)
libcfunk_check_symbol_exists(strtoll "stdlib.h" HAVE_STRTOLL)

set(LIBCFUNK_DECLARE_STRTOL 1)
set(LIBCFUNK_DECLARE_STRTOLL 1)

if (NOT HAVE_STRTOL)
  libcfunk_add_sources("strtol.c")
endif ()

if (NOT HAVE_STRTOLL)
  libcfunk_add_sources("strtoll.c")
endif ()
