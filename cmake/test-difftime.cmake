
include_guard(GLOBAL)

add_executable(test-difftime)

target_link_libraries(test-difftime PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-difftime PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-difftime.c
)

set_target_properties(test-difftime PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-difftime" COMMAND test-difftime)
