
include_guard(GLOBAL)

add_executable(test-fread)

target_link_libraries(test-fread PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fread PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fread.c
)

set_target_properties(test-fread PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fread" COMMAND test-fread)
