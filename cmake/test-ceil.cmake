
include_guard(GLOBAL)

add_executable(test-ceil)

target_link_libraries(test-ceil PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ceil PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ceil.c
)

set_target_properties(test-ceil PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ceil" COMMAND test-ceil)
