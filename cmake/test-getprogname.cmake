
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-getprogname)

target_link_libraries(test-getprogname PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getprogname PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getprogname.c
)

set_target_properties(test-getprogname PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getprogname" COMMAND test-getprogname)
