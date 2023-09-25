
include_guard(GLOBAL)

add_executable(test-filename-join-extension)

target_link_libraries(test-filename-join-extension PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-filename-join-extension PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-filename-join-extension.c
)

set_target_properties(test-filename-join-extension PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
