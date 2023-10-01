
include_guard(GLOBAL)

add_executable(test-binary-mode)

target_link_libraries(test-binary-mode PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-binary-mode PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-binary-mode.c
)

set_target_properties(test-binary-mode PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
