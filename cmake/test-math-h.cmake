
include_guard(GLOBAL)

add_executable(test-math-h)

target_link_libraries(test-math-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-math-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-math-h.c
)

set_target_properties(test-math-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-math-h" COMMAND test-math-h)
