
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)

add_executable(test-chown)

target_link_libraries(test-chown PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-chown PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-chown.c
)

set_target_properties(test-chown PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-chown" COMMAND test-chown)
set_tests_properties("test-chown" PROPERTIES SKIP_RETURN_CODE 77)
