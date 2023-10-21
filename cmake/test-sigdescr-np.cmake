
include_guard(GLOBAL)

add_executable(test-sigdescr-np)

target_link_libraries(test-sigdescr-np PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sigdescr-np PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sigdescr-np.c
)

set_target_properties(test-sigdescr-np PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sigdescr-np" COMMAND test-sigdescr-np)
