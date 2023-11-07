
include_guard(GLOBAL)

add_executable(test-call_once)

target_link_libraries(test-call_once PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-call_once PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-call_once.c
)

set_target_properties(test-call_once PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-call_once" COMMAND test-call_once)
