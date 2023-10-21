
include_guard(GLOBAL)

add_executable(test-root-gid)

target_link_libraries(test-root-gid PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-root-gid PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-root-gid.c
)

set_target_properties(test-root-gid PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-root-gid" COMMAND test-root-gid)
