
include_guard(GLOBAL)

add_executable(test-strncasecmp)

target_link_libraries(test-strncasecmp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strncasecmp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strncasecmp.c
)

set_target_properties(test-strncasecmp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strncasecmp" COMMAND test-strncasecmp)
