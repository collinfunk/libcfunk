
include_guard(GLOBAL)

libcfunk_add_sources("splay-tree.h;splay-tree.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-splay-tree.cmake)
endif ()

