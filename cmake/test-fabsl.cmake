
include_guard(GLOBAL)

add_executable(test-fabsl)

target_link_libraries(test-fabsl PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fabsl PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fabsl.c
)

set_target_properties(test-fabsl PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fabsl" COMMAND test-fabsl)
