
include_guard(GLOBAL)

add_executable(test-strtof)

target_link_libraries(test-strtof PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strtof PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strtof.c
)

set_target_properties(test-strtof PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strtof" COMMAND test-strtof)
