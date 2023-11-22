
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-environ)

target_link_libraries(test-environ PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-environ PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-environ.c
)

set_target_properties(test-environ PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-environ" COMMAND test-environ)

# Set an environment variable.
set_tests_properties("test-environ" PROPERTIES ENVIRONMENT "TEST_ENVIRON_VALUE=ok")
