
include_guard(GLOBAL)

add_executable(test-sigdescr_np)

target_link_libraries(test-sigdescr_np PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sigdescr_np PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sigdescr_np.c
)

set_target_properties(test-sigdescr_np PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sigdescr_np" COMMAND test-sigdescr_np)
