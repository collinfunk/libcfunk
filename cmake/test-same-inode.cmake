
include_guard(GLOBAL)

add_executable(test-same-inode)

target_link_libraries(test-same-inode PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-same-inode PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-same-inode.c
)

set_target_properties(test-same-inode PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-same-inode" COMMAND test-same-inode)
