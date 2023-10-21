
include_guard(GLOBAL)

add_executable(test-__builtin_expect)

target_link_libraries(test-__builtin_expect PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-__builtin_expect PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-__builtin_expect.c
)

set_target_properties(test-__builtin_expect PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-__builtin_expect" COMMAND test-__builtin_expect)
