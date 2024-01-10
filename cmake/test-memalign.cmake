
include_guard(GLOBAL)

add_executable(test-memalign)

target_link_libraries(test-memalign PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-memalign PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-memalign.c
)

set_target_properties(test-memalign PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-memalign" COMMAND test-memalign)
