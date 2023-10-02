
include_guard(GLOBAL)

add_executable(test-realloc)

target_link_libraries(test-realloc PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-realloc PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-realloc.c
)

set_target_properties(test-realloc PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
