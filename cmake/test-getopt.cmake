
include_guard(GLOBAL)

add_executable(test-getopt)

target_link_libraries(test-getopt PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getopt PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getopt.c
)

set_target_properties(test-getopt PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getopt" COMMAND test-getopt)
