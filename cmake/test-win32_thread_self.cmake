
include_guard(GLOBAL)

add_executable(test-win32_thread_self)

target_link_libraries(test-win32_thread_self PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-win32_thread_self PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-win32_thread_self.c
)

set_target_properties(test-win32_thread_self PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-win32_thread_self" COMMAND test-win32_thread_self)
