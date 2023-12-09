
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/getcwd.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unsetenv.cmake)

add_executable(test-get_current_dir_name)

target_link_libraries(test-get_current_dir_name PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-get_current_dir_name PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-get_current_dir_name.c
)

set_target_properties(test-get_current_dir_name PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-get_current_dir_name" COMMAND test-get_current_dir_name)
