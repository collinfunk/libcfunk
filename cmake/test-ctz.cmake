
include_guard(GLOBAL)

add_executable(test-ctz)

target_link_libraries(test-ctz PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ctz PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ctz.c
)

set_target_properties(test-ctz PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
