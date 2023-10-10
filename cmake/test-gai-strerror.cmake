
include_guard(GLOBAL)

add_executable(test-gai-strerror)

target_link_libraries(test-gai-strerror PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-gai-strerror PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-gai-strerror.c
)

set_target_properties(test-gai-strerror PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
