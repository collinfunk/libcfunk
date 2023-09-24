
include_guard(GLOBAL)

add_executable(test-group-member)

target_link_libraries(test-group-member PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-group-member PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-group-member.c
)

set_target_properties(test-group-member PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
