
include_guard(GLOBAL)

add_executable(test-open-standard-streams)

target_link_libraries(test-open-standard-streams PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-open-standard-streams PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-open-standard-streams.c
)

set_target_properties(test-open-standard-streams PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-open-standard-streams" COMMAND test-open-standard-streams)
