
include_guard(GLOBAL)

add_executable(test-fnmatch-h)

target_link_libraries(test-fnmatch-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fnmatch-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fnmatch-h.c
)

set_target_properties(test-fnmatch-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fnmatch-h" COMMAND test-fnmatch-h)
