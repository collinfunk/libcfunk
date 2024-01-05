
include_guard(GLOBAL)

add_executable(test-pthread_sigmask)

target_link_libraries(test-pthread_sigmask PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-pthread_sigmask PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-pthread_sigmask.c
)

set_target_properties(test-pthread_sigmask PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-pthread_sigmask" COMMAND test-pthread_sigmask)
