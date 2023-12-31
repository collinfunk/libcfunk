
include_guard(GLOBAL)

add_executable(test-posix_fadvise)

target_link_libraries(test-posix_fadvise PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-posix_fadvise PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-posix_fadvise.c
)

set_target_properties(test-posix_fadvise PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-posix_fadvise" COMMAND test-posix_fadvise)
