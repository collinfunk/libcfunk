
include_guard(GLOBAL)

add_executable(test-same_inode)

target_link_libraries(test-same_inode PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-same_inode PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-same_inode.c
)

set_target_properties(test-same_inode PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-same_inode" COMMAND test-same_inode)
