
include_guard(GLOBAL)

add_executable(test-bstree)

target_link_libraries(test-bstree PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-bstree PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-bstree.c
)

set_target_properties(test-bstree PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-bstree" COMMAND test-bstree)
