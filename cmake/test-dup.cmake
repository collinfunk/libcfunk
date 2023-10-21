
include_guard(GLOBAL)

add_executable(test-dup)

target_link_libraries(test-dup PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-dup PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-dup.c
)

set_target_properties(test-dup PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-dup" COMMAND test-dup)
