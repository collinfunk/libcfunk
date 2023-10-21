
include_guard(GLOBAL)

add_executable(test-base16)

target_link_libraries(test-base16 PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-base16 PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-base16.c
)

set_target_properties(test-base16 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-base16" COMMAND test-base16)
