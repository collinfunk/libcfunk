
include_guard(GLOBAL)

add_executable(test-strtold)

target_link_libraries(test-strtold PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strtold PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strtold.c
)

set_target_properties(test-strtold PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strtold" COMMAND test-strtold)
