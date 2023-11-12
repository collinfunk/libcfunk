
include_guard(GLOBAL)

add_executable(test-sigabbrev_np)

target_link_libraries(test-sigabbrev_np PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sigabbrev_np PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sigabbrev_np.c
)

set_target_properties(test-sigabbrev_np PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sigabbrev_np" COMMAND test-sigabbrev_np)
