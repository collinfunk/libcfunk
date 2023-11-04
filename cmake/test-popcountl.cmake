
include_guard(GLOBAL)

add_executable(test-popcountl)

target_link_libraries(test-popcountl PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-popcountl PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-popcountl.c
)

set_target_properties(test-popcountl PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-popcountl" COMMAND test-popcountl)
