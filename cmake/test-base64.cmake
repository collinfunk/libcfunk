
include_guard(GLOBAL)

add_executable(test-base64)

target_link_libraries(test-base64 PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-base64 PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-base64.c
)

set_target_properties(test-base64 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
