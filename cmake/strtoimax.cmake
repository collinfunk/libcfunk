
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/inttypes.cmake)

libcfunk_check_symbol_exists(strtoimax "inttypes.h" HAVE_STRTOIMAX)

set(LIBCFUNK_DECLARE_STRTOIMAX 1)

if (NOT HAVE_STRTOIMAX)
  libcfunk_add_sources("strtoimax.c")
endif ()
