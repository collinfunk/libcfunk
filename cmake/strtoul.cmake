
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)

libcfunk_check_symbol_exists(strtoul "stdlib.h" HAVE_STRTOUL)
libcfunk_check_symbol_exists(strtoull "stdlib.h" HAVE_STRTOULL)

set(LIBCFUNK_DECLARE_STRTOUL 1)
set(LIBCFUNK_DECLARE_STRTOULL 1)

if (NOT HAVE_STRTOUL)
  libcfunk_add_sources("strtoul.c")
endif ()

if (NOT HAVE_STRTOULL)
  libcfunk_add_sources("strtoull.c")
endif ()
