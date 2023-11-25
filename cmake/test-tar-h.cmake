
include_guard(GLOBAL)

add_executable(test-tar-h)

target_link_libraries(test-tar-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-tar-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-tar-h.c
)

set_target_properties(test-tar-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-tar-h" COMMAND test-tar-h)
