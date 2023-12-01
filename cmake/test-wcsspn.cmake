
include_guard(GLOBAL)

add_executable(test-wcsspn)

target_link_libraries(test-wcsspn PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wcsspn PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wcsspn.c
)

set_target_properties(test-wcsspn PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wcsspn" COMMAND test-wcsspn)
