
include_guard(GLOBAL)

add_executable(test-win32_thread_exit)

target_link_libraries(test-win32_thread_exit PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-win32_thread_exit PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-win32_thread_exit.c
)

set_target_properties(test-win32_thread_exit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-win32_thread_exit" COMMAND test-win32_thread_exit)
