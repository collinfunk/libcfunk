
include_guard(GLOBAL)

add_executable(test-fopen)

target_link_libraries(test-fopen PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fopen PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fopen.c
)

set_target_properties(test-fopen PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fopen" COMMAND test-fopen)
