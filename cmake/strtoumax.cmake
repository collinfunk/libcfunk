
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/inttypes.cmake)

libcfunk_check_symbol_exists(strtoumax "inttypes.h" HAVE_STRTOUMAX)

set(LIBCFUNK_DECLARE_STRTOUMAX 1)

if (NOT HAVE_STRTOUMAX)
  libcfunk_add_sources("strtoumax.c")
endif ()
