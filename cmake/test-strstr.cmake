
include_guard(GLOBAL)

add_executable(test-strstr)

target_link_libraries(test-strstr PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strstr PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strstr.c
)

set_target_properties(test-strstr PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strstr" COMMAND test-strstr)
