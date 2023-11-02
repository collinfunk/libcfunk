
include_guard(GLOBAL)

add_executable(test-sigdelset)

target_link_libraries(test-sigdelset PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sigdelset PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sigdelset.c
)

set_target_properties(test-sigdelset PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sigdelset" COMMAND test-sigdelset)
