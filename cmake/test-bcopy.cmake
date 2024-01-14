
include_guard(GLOBAL)

add_executable(test-bcopy)

target_link_libraries(test-bcopy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-bcopy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-bcopy.c
)

set_target_properties(test-bcopy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-bcopy" COMMAND test-bcopy)
