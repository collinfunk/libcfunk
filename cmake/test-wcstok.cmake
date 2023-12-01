
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wcscmp.cmake)

add_executable(test-wcstok)

target_link_libraries(test-wcstok PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wcstok PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wcstok.c
)

set_target_properties(test-wcstok PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wcstok" COMMAND test-wcstok)
