
include_guard(GLOBAL)

add_executable(test-strcasecmp)

target_link_libraries(test-strcasecmp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strcasecmp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strcasecmp.c
)

set_target_properties(test-strcasecmp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strcasecmp" COMMAND test-strcasecmp)
