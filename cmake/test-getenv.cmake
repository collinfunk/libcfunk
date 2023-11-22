
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-getenv)

target_link_libraries(test-getenv PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getenv PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getenv.c
)

set_target_properties(test-getenv PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getenv" COMMAND test-getenv)

# Set an environment variable.
set_tests_properties("test-getenv" PROPERTIES ENVIRONMENT "TEST_GETENV_VALUE=ok")
