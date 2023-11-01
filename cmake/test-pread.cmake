
include_guard(GLOBAL)

add_executable(test-pread)

target_link_libraries(test-pread PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-pread PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-pread.c
)

set_target_properties(test-pread PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-pread" COMMAND test-pread)
