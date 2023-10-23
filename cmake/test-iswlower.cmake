
include_guard(GLOBAL)

add_executable(test-iswlower)

target_link_libraries(test-iswlower PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswlower PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswlower.c
)

set_target_properties(test-iswlower PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswlower" COMMAND test-iswlower)
