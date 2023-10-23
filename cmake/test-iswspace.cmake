
include_guard(GLOBAL)

add_executable(test-iswspace)

target_link_libraries(test-iswspace PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswspace PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswspace.c
)

set_target_properties(test-iswspace PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswspace" COMMAND test-iswspace)
