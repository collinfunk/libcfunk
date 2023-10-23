
include_guard(GLOBAL)

add_executable(test-iswupper)

target_link_libraries(test-iswupper PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswupper PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswupper.c
)

set_target_properties(test-iswupper PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswupper" COMMAND test-iswupper)
