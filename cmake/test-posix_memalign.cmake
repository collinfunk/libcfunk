
include_guard(GLOBAL)

add_executable(test-posix_memalign)

target_link_libraries(test-posix_memalign PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-posix_memalign PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-posix_memalign.c
)

set_target_properties(test-posix_memalign PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-posix_memalign" COMMAND test-posix_memalign)
