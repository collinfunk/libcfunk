
include_guard(GLOBAL)

add_executable(test-rbtree)

target_link_libraries(test-rbtree PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-rbtree PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-rbtree.c
)

set_target_properties(test-rbtree PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-rbtree" COMMAND test-rbtree)
