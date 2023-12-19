
include_guard(GLOBAL)

add_executable(test-freopen)

target_link_libraries(test-freopen PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-freopen PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-freopen.c
)

set_target_properties(test-freopen PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-freopen" COMMAND test-freopen)
