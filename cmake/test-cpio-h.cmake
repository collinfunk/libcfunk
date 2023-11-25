
include_guard(GLOBAL)

add_executable(test-cpio-h)

target_link_libraries(test-cpio-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-cpio-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-cpio-h.c
)

set_target_properties(test-cpio-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-cpio-h" COMMAND test-cpio-h)
