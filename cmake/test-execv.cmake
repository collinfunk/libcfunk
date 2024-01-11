
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/test-exec-child.cmake)

add_executable(test-execv)

target_link_libraries(test-execv PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-execv PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-execv.c
)

set_target_properties(test-execv PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-execv" COMMAND test-execv)
