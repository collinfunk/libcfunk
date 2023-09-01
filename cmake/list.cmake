
include_guard(GLOBAL)

libcfunk_add_sources("list.h;list.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-list.cmake)
endif ()
