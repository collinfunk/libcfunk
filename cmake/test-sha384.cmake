
include_guard(GLOBAL)

add_executable(test-sha384)

target_link_libraries(test-sha384 PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sha384 PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sha384.c
)

set_target_properties(test-sha384 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sha384" COMMAND test-sha384)
