
include_guard(GLOBAL)

add_executable(test-slist)

target_link_libraries(test-slist PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-slist PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-slist.c
)

set_target_properties(test-slist PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-slist" COMMAND test-slist)
