
include_guard(GLOBAL)

add_executable(test-labs)

target_link_libraries(test-labs PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-labs PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-labs.c
)

set_target_properties(test-labs PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-labs" COMMAND test-labs)
