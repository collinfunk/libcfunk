
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/isatty.cmake)

add_executable(test-select)

target_link_libraries(test-select PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-select PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-select.c
)

set_target_properties(test-select PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-select" COMMAND test-select)
