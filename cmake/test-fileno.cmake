
include_guard(GLOBAL)

add_executable(test-fileno)

target_link_libraries(test-fileno PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fileno PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fileno.c
)

set_target_properties(test-fileno PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fileno" COMMAND test-fileno)
