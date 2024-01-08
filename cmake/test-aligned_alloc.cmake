
include_guard(GLOBAL)

add_executable(test-aligned_alloc)

target_link_libraries(test-aligned_alloc PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-aligned_alloc PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-aligned_alloc.c
)

set_target_properties(test-aligned_alloc PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-aligned_alloc" COMMAND test-aligned_alloc)
