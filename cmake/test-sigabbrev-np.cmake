
include_guard(GLOBAL)

add_executable(test-sigabbrev-np)

target_link_libraries(test-sigabbrev-np PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sigabbrev-np PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sigabbrev-np.c
)

set_target_properties(test-sigabbrev-np PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
