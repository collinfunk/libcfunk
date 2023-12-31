
include_guard(GLOBAL)

add_executable(test-filename-strip-extension)

target_link_libraries(test-filename-strip-extension PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-filename-strip-extension PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-filename-strip-extension.c
)

set_target_properties(test-filename-strip-extension PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-filename-strip-extension" COMMAND test-filename-strip-extension)
