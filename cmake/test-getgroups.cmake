
include_guard(GLOBAL)

add_executable(test-getgroups)

target_link_libraries(test-getgroups PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getgroups PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getgroups.c
)

set_target_properties(test-getgroups PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getgroups" COMMAND test-getgroups)
