
include_guard(GLOBAL)

add_executable(test-strings-h)

target_link_libraries(test-strings-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strings-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strings-h.c
)

set_target_properties(test-strings-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strings-h" COMMAND test-strings-h)
