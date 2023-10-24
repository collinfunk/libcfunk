
include_guard(GLOBAL)

add_executable(test-wcscasecmp)

target_link_libraries(test-wcscasecmp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wcscasecmp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wcscasecmp.c
)

set_target_properties(test-wcscasecmp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wcscasecmp" COMMAND test-wcscasecmp)
