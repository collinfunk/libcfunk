
include_guard(GLOBAL)

add_executable(test-nl_langinfo)

target_link_libraries(test-nl_langinfo PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-nl_langinfo PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-nl_langinfo.c
)

set_target_properties(test-nl_langinfo PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-nl_langinfo" COMMAND test-nl_langinfo)
