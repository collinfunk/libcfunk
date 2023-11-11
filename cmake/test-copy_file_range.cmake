
include_guard(GLOBAL)

add_executable(test-copy_file_range)

target_link_libraries(test-copy_file_range PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-copy_file_range PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-copy_file_range.c
)

set_target_properties(test-copy_file_range PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-copy_file_range" COMMAND test-copy_file_range)
