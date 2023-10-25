
include_guard(GLOBAL)

add_executable(test-toupper)

target_link_libraries(test-toupper PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-toupper PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-toupper.c
)

set_target_properties(test-toupper PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-toupper" COMMAND test-toupper)
