
include_guard(GLOBAL)

add_executable(test-a64l)

target_link_libraries(test-a64l PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-a64l PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-a64l.c
)

set_target_properties(test-a64l PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-a64l" COMMAND test-a64l)
