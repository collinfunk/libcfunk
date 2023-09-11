
include_guard(GLOBAL)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/splay-tree.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/splay-tree.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-splay-tree.cmake)
endif ()

