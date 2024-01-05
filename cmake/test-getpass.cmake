
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/isatty.cmake)

add_executable(test-getpass)

target_link_libraries(test-getpass PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getpass PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getpass.c
)

set_target_properties(test-getpass PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getpass" COMMAND test-getpass)
set_tests_properties("test-getpass" PROPERTIES SKIP_RETURN_CODE 77)
