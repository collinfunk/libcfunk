
include_guard(GLOBAL)

add_executable(test-recvfrom)

target_link_libraries(test-recvfrom PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-recvfrom PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-recvfrom.c
)

set_target_properties(test-recvfrom PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-recvfrom" COMMAND test-recvfrom)
