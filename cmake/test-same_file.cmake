
include_guard(GLOBAL)

add_executable(test-same_file)

target_link_libraries(test-same_file PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-same_file PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-same_file.c
)

set_target_properties(test-same_file PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-same_file" COMMAND test-same_file)
