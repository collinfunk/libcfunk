
include_guard(GLOBAL)

add_executable(test-offsetof)

target_link_libraries(test-offsetof PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-offsetof PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-offsetof.c
)

set_target_properties(test-offsetof PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-offsetof" COMMAND test-offsetof)
