
include_guard(GLOBAL)

add_executable(test-fwrite)

target_link_libraries(test-fwrite PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fwrite PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fwrite.c
)

set_target_properties(test-fwrite PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fwrite" COMMAND test-fwrite)
