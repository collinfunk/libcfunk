
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/getenv.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/putenv.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-unsetenv)

target_link_libraries(test-unsetenv PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-unsetenv PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-unsetenv.c
)

set_target_properties(test-unsetenv PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-unsetenv" COMMAND test-unsetenv)
