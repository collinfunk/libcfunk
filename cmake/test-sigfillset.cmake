
include_guard(GLOBAL)

add_executable(test-sigfillset)

target_link_libraries(test-sigfillset PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sigfillset PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sigfillset.c
)

set_target_properties(test-sigfillset PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sigfillset" COMMAND test-sigfillset)
