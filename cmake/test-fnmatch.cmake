
include_guard(GLOBAL)

add_executable(test-fnmatch)

target_link_libraries(test-fnmatch PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fnmatch PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fnmatch.c
)

set_target_properties(test-fnmatch PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fnmatch" COMMAND test-fnmatch)
