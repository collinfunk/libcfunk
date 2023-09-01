
include_guard(GLOBAL)

libcfunk_add_sources("dirname.h;dirname.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-dirname.cmake)
endif ()
