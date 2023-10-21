
include_guard(GLOBAL)

add_executable(test-splay-tree)

target_link_libraries(test-splay-tree PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-splay-tree PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-splay-tree.c
)

set_target_properties(test-splay-tree PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-splay-tree" COMMAND test-splay-tree)
