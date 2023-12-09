
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)

add_executable(test-getcwd)

target_link_libraries(test-getcwd PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getcwd PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getcwd.c
)

set_target_properties(test-getcwd PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getcwd" COMMAND test-getcwd)
