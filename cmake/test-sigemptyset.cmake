
include_guard(GLOBAL)

add_executable(test-sigemptyset)

target_link_libraries(test-sigemptyset PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sigemptyset PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sigemptyset.c
)

set_target_properties(test-sigemptyset PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sigemptyset" COMMAND test-sigemptyset)
