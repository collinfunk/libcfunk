
include_guard(GLOBAL)

add_executable(test-memset)

target_link_libraries(test-memset PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-memset PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-memset.c
)

set_target_properties(test-memset PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-memset" COMMAND test-memset)
