
include_guard(GLOBAL)

add_executable(test-freeaddrinfo)

target_link_libraries(test-freeaddrinfo PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-freeaddrinfo PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-freeaddrinfo.c
)

set_target_properties(test-freeaddrinfo PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-freeaddrinfo" COMMAND test-freeaddrinfo)
