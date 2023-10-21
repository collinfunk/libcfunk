
include_guard(GLOBAL)

add_executable(test-netdb-h)

target_link_libraries(test-netdb-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-netdb-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-netdb-h.c
)

set_target_properties(test-netdb-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-netdb-h" COMMAND test-netdb-h)
