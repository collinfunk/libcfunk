
include_guard(GLOBAL)

add_executable(test-same-file)

target_link_libraries(test-same-file PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-same-file PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-same-file.c
)

set_target_properties(test-same-file PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
