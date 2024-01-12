
include_guard(GLOBAL)

add_executable(test-socket)

target_link_libraries(test-socket PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-socket PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-socket.c
)

set_target_properties(test-socket PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-socket" COMMAND test-socket)
