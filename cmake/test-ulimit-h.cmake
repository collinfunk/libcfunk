
include_guard(GLOBAL)

add_executable(test-ulimit-h)

target_link_libraries(test-ulimit-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ulimit-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ulimit-h.c
)

set_target_properties(test-ulimit-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ulimit-h" COMMAND test-ulimit-h)
