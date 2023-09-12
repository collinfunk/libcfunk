
include_guard(GLOBAL)

add_executable(test-filename-last-component)

target_link_libraries(test-filename-last-component PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-filename-last-component PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-filename-last-component.c
)

set_target_properties(test-filename-last-component PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
