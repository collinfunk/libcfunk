
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/iswprint.cmake)

add_executable(test-wcwidth)

target_link_libraries(test-wcwidth PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wcwidth PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wcwidth.c
)

set_target_properties(test-wcwidth PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wcwidth" COMMAND test-wcwidth)
