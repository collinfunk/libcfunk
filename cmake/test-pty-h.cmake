
include_guard(GLOBAL)

add_executable(test-pty-h)

target_link_libraries(test-pty-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-pty-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-pty-h.c
)

set_target_properties(test-pty-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-pty-h" COMMAND test-pty-h)
