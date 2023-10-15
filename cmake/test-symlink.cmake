
include_guard(GLOBAL)

add_executable(test-symlink)

target_link_libraries(test-symlink PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-symlink PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-symlink.c
)

set_target_properties(test-symlink PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
