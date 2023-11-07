
include_guard(GLOBAL)

add_executable(test-threads-h)

target_link_libraries(test-threads-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-threads-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-threads-h.c
)

set_target_properties(test-threads-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-threads-h" COMMAND test-threads-h)
