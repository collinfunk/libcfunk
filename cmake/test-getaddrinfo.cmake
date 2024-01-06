
include_guard(GLOBAL)

add_executable(test-getaddrinfo)

target_link_libraries(test-getaddrinfo PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getaddrinfo PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getaddrinfo.c
)

set_target_properties(test-getaddrinfo PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getaddrinfo" COMMAND test-getaddrinfo)
