
include_guard(GLOBAL)

add_executable(test-floorf)

target_link_libraries(test-floorf PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-floorf PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-floorf.c
)

set_target_properties(test-floorf PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-floorf" COMMAND test-floorf)
