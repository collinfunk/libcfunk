
include_guard(GLOBAL)

add_executable(test-dirfd)

target_link_libraries(test-dirfd PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-dirfd PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-dirfd.c
)

set_target_properties(test-dirfd PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
