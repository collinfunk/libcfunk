
include_guard(GLOBAL)

add_executable(test-uname)

target_link_libraries(test-uname PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-uname PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-uname.c
)

set_target_properties(test-uname PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-uname" COMMAND test-uname)
