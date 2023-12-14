
include_guard(GLOBAL)

add_executable(test-forkpty)

target_link_libraries(test-forkpty PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-forkpty PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-forkpty.c
)

set_target_properties(test-forkpty PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-forkpty" COMMAND test-forkpty)
