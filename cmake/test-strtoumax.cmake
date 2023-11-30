
include_guard(GLOBAL)

add_executable(test-strtoumax)

target_link_libraries(test-strtoumax PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strtoumax PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strtoumax.c
)

set_target_properties(test-strtoumax PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strtoumax" COMMAND test-strtoumax)
