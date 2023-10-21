
include_guard(GLOBAL)

add_executable(test-endian-h)

target_link_libraries(test-endian-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-endian-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-endian-h.c
)

set_target_properties(test-endian-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-endian-h" COMMAND test-endian-h)
