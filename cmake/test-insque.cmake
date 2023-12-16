
include_guard(GLOBAL)

add_executable(test-insque)

target_link_libraries(test-insque PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-insque PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-insque.c
)

set_target_properties(test-insque PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-insque" COMMAND test-insque)
