
include_guard(GLOBAL)

add_executable(test-getpid)

target_link_libraries(test-getpid PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getpid PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getpid.c
)

set_target_properties(test-getpid PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getpid" COMMAND test-getpid)
