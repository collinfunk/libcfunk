
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/time.cmake)

libcfunk_check_symbol_exists(dysize "time.h" HAVE_DYSIZE)

set(LIBCFUNK_DECLARE_DYSIZE 1)

if (NOT HAVE_DYSIZE)
  libcfunk_add_sources("dysize.c")
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-dysize.cmake)
endif ()

