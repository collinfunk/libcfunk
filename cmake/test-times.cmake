
include_guard(GLOBAL)

add_executable(test-times)

target_link_libraries(test-times PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-times PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-times.c
)

set_target_properties(test-times PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)