
include_guard(GLOBAL)

add_executable(test-group_member)

target_link_libraries(test-group_member PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-group_member PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-group_member.c
)

set_target_properties(test-group_member PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-group_member" COMMAND test-group_member)
