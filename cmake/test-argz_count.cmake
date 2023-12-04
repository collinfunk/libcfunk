
include_guard(GLOBAL)

add_executable(test-argz_count)

target_link_libraries(test-argz_count PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-argz_count PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-argz_count.c
)

set_target_properties(test-argz_count PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-argz_count" COMMAND test-argz_count)
