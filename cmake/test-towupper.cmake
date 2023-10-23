
include_guard(GLOBAL)

add_executable(test-towupper)

target_link_libraries(test-towupper PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-towupper PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-towupper.c
)

set_target_properties(test-towupper PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-towupper" COMMAND test-towupper)
