
include_guard(GLOBAL)

add_executable(test-sockets)

target_link_libraries(test-sockets PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sockets PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sockets.c
)

set_target_properties(test-sockets PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sockets" COMMAND test-sockets)
