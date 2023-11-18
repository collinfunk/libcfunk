
include_guard(GLOBAL)

add_executable(test-inet_pton)

target_link_libraries(test-inet_pton PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-inet_pton PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-inet_pton.c
)

set_target_properties(test-inet_pton PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-inet_pton" COMMAND test-inet_pton)
