
include_guard(GLOBAL)

add_executable(test-isupper)

target_link_libraries(test-isupper PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-isupper PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-isupper.c
)

set_target_properties(test-isupper PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-isupper" COMMAND test-isupper)
