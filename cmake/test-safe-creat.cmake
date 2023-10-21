
include_guard(GLOBAL)

add_executable(test-safe-creat)

target_link_libraries(test-safe-creat PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-safe-creat PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-safe-creat.c
)

set_target_properties(test-safe-creat PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-safe-creat" COMMAND test-safe-creat)
