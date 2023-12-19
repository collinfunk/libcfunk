
include_guard(GLOBAL)

add_executable(test-ferror)

target_link_libraries(test-ferror PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ferror PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ferror.c
)

set_target_properties(test-ferror PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ferror" COMMAND test-ferror)
