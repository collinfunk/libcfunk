
include_guard(GLOBAL)

add_executable(test-getppid)

target_link_libraries(test-getppid PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getppid PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getppid.c
)

set_target_properties(test-getppid PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getppid" COMMAND test-getppid)
