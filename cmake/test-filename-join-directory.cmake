
include_guard(GLOBAL)

add_executable(test-filename-join-directory)

target_link_libraries(test-filename-join-directory PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-filename-join-directory PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-filename-join-directory.c
)

set_target_properties(test-filename-join-directory PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
