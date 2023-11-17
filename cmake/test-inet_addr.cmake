
include_guard(GLOBAL)

add_executable(test-inet_addr)

target_link_libraries(test-inet_addr PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-inet_addr PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-inet_addr.c
)

set_target_properties(test-inet_addr PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-inet_addr" COMMAND test-inet_addr)
