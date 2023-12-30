
include_guard(GLOBAL)

add_executable(test-clock)

target_link_libraries(test-clock PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-clock PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-clock.c
)

set_target_properties(test-clock PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-clock" COMMAND test-clock)
