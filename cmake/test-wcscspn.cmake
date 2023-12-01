
include_guard(GLOBAL)

add_executable(test-wcscspn)

target_link_libraries(test-wcscspn PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wcscspn PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wcscspn.c
)

set_target_properties(test-wcscspn PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wcscspn" COMMAND test-wcscspn)
