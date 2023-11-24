
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/getenv.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-putenv)

target_link_libraries(test-putenv PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-putenv PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-putenv.c
)

set_target_properties(test-putenv PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-putenv" COMMAND test-putenv)
