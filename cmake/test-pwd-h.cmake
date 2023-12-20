
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-pwd-h)

target_link_libraries(test-pwd-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-pwd-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-pwd-h.c
)

set_target_properties(test-pwd-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-pwd-h" COMMAND test-pwd-h)
