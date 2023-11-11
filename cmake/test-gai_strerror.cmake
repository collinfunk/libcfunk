
include_guard(GLOBAL)

add_executable(test-gai_strerror)

target_link_libraries(test-gai_strerror PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-gai_strerror PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-gai_strerror.c
)

set_target_properties(test-gai_strerror PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-gai_strerror" COMMAND test-gai_strerror)
