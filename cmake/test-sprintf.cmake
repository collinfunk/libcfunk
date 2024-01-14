
include_guard(GLOBAL)

add_executable(test-sprintf)

target_link_libraries(test-sprintf PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sprintf PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sprintf.c
)

set_target_properties(test-sprintf PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sprintf" COMMAND test-sprintf)
