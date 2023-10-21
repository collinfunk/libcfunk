
include_guard(GLOBAL)

add_executable(test-safe-dup)

target_link_libraries(test-safe-dup PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-safe-dup PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-safe-dup.c
)

set_target_properties(test-safe-dup PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-safe-dup" COMMAND test-safe-dup)
