
include_guard(GLOBAL)

add_executable(test-flsl)

target_link_libraries(test-flsl PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-flsl PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-flsl.c
)

set_target_properties(test-flsl PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-flsl" COMMAND test-flsl)
