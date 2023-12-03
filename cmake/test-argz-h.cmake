
include_guard(GLOBAL)

add_executable(test-argz-h)

target_link_libraries(test-argz-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-argz-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-argz-h.c
)

set_target_properties(test-argz-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-argz-h" COMMAND test-argz-h)
