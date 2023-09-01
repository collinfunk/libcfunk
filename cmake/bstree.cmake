
include_guard(GLOBAL)

libcfunk_add_sources("bstree.h;bstree.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-bstree.cmake)
endif ()
