
include_guard(GLOBAL)

add_executable(test-block-size)

target_link_libraries(test-block-size PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-block-size PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-block-size.c
)

set_target_properties(test-block-size PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-block-size" COMMAND test-block-size)
