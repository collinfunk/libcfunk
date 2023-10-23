
include_guard(GLOBAL)

add_executable(test-error-h)

target_link_libraries(test-error-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-error-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-error-h.c
)

set_target_properties(test-error-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-error-h" COMMAND test-error-h)
