
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/getenv.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unsetenv.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-setenv)

target_link_libraries(test-setenv PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-setenv PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-setenv.c
)

set_target_properties(test-setenv PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-setenv" COMMAND test-setenv)
