
include_guard(GLOBAL)

add_executable(test-win32-once)

target_link_libraries(test-win32-once PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-win32-once PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-win32-once.c
)

set_target_properties(test-win32-once PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-win32-once" COMMAND test-win32-once)
