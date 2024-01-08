
include_guard(GLOBAL)

add_executable(test-posix_fallocate)

target_link_libraries(test-posix_fallocate PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-posix_fallocate PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-posix_fallocate.c
)

set_target_properties(test-posix_fallocate PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-posix_fallocate" COMMAND test-posix_fallocate)
