
include_guard(GLOBAL)

add_executable(test-sigprocmask)

target_link_libraries(test-sigprocmask PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sigprocmask PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sigprocmask.c
)

set_target_properties(test-sigprocmask PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sigprocmask" COMMAND test-sigprocmask)
