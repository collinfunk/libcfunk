
include_guard(GLOBAL)

add_executable(test-wctype-h)

target_link_libraries(test-wctype-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wctype-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wctype-h.c
)

set_target_properties(test-wctype-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wctype-h" COMMAND test-wctype-h)
