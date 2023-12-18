
include_guard(GLOBAL)

add_executable(test-tmpfile)

target_link_libraries(test-tmpfile PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-tmpfile PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-tmpfile.c
)

set_target_properties(test-tmpfile PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-tmpfile" COMMAND test-tmpfile)
