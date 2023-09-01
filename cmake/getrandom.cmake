
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/sys-random.cmake)

libcfunk_check_symbol_exists(getrandom "sys/random.h" HAVE_GETRANDOM)

set(LIBCFUNK_DECLARE_GETRANDOM 1)

if (NOT HAVE_GETRANDOM)
  libcfunk_add_sources("getrandom.c")
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-getrandom.cmake)
endif ()

