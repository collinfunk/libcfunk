
include_guard(GLOBAL)

add_executable(test-memdup)

target_link_libraries(test-memdup PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-memdup PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-memdup.c
)

set_target_properties(test-memdup PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-memdup" COMMAND test-memdup)
