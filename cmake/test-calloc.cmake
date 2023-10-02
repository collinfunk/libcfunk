
include_guard(GLOBAL)

add_executable(test-calloc)

target_link_libraries(test-calloc PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-calloc PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-calloc.c
)

set_target_properties(test-calloc PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
