
include_guard(GLOBAL)

add_executable(test-copy-file-range)

target_link_libraries(test-copy-file-range PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-copy-file-range PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-copy-file-range.c
)

set_target_properties(test-copy-file-range PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
