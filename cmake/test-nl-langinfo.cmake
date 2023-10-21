
include_guard(GLOBAL)

add_executable(test-nl-langinfo)

target_link_libraries(test-nl-langinfo PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-nl-langinfo PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-nl-langinfo.c
)

set_target_properties(test-nl-langinfo PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-nl-langinfo" COMMAND test-nl-langinfo)
