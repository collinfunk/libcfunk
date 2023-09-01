
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdio.cmake)

libcfunk_check_symbol_exists(getdelim "stdio.h" HAVE_GETDELIM)

set(LIBCFUNK_DECLARE_GETDELIM 1)

if (NOT HAVE_GETDELIM)
  libcfunk_add_sources("getdelim.c")
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-getdelim.cmake)
endif ()

