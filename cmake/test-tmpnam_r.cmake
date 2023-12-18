
include_guard(GLOBAL)

add_executable(test-tmpnam_r)

target_link_libraries(test-tmpnam_r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-tmpnam_r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-tmpnam_r.c
)

set_target_properties(test-tmpnam_r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-tmpnam_r" COMMAND test-tmpnam_r)
