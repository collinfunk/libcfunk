
include_guard(GLOBAL)

add_executable(test-getopt_long_only)

target_link_libraries(test-getopt_long_only PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getopt_long_only PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getopt_long_only.c
)

set_target_properties(test-getopt_long_only PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getopt_long_only" COMMAND test-getopt_long_only)
