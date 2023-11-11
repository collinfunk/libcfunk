
include_guard(GLOBAL)

add_executable(test-strerrordesc_np)

target_link_libraries(test-strerrordesc_np PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strerrordesc_np PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strerrordesc_np.c
)

set_target_properties(test-strerrordesc_np PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strerrordesc_np" COMMAND test-strerrordesc_np)
