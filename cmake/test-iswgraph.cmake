
include_guard(GLOBAL)

add_executable(test-iswgraph)

target_link_libraries(test-iswgraph PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswgraph PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswgraph.c
)

set_target_properties(test-iswgraph PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswgraph" COMMAND test-iswgraph)
