
include_guard(GLOBAL)

add_executable(test-localcharset)

target_link_libraries(test-localcharset PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-localcharset PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-localcharset.c
)

set_target_properties(test-localcharset PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-localcharset" COMMAND test-localcharset)
