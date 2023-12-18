
include_guard(GLOBAL)

add_executable(test-tmpnam)

target_link_libraries(test-tmpnam PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-tmpnam PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-tmpnam.c
)

set_target_properties(test-tmpnam PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-tmpnam" COMMAND test-tmpnam)
