
include_guard(GLOBAL)

add_executable(test-malloc-h)

target_link_libraries(test-malloc-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-malloc-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-malloc-h.c
)

set_target_properties(test-malloc-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-malloc-h" COMMAND test-malloc-h)
