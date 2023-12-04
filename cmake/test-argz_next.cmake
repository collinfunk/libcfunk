
include_guard(GLOBAL)

add_executable(test-argz_next)

target_link_libraries(test-argz_next PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-argz_next PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-argz_next.c
)

set_target_properties(test-argz_next PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-argz_next" COMMAND test-argz_next)
