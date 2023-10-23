
include_guard(GLOBAL)

add_executable(test-ctype-h)

target_link_libraries(test-ctype-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ctype-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ctype-h.c
)

set_target_properties(test-ctype-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ctype-h" COMMAND test-ctype-h)
