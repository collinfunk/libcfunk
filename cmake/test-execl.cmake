
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/test-exec-child.cmake)

add_executable(test-execl)

target_link_libraries(test-execl PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-execl PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-execl.c
)

set_target_properties(test-execl PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-execl" COMMAND test-execl)
