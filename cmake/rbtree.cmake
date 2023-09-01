
include_guard(GLOBAL)

libcfunk_add_sources("rbtree.h;rbtree.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-rbtree.cmake)
endif ()

