
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-strtok)

target_link_libraries(test-strtok PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strtok PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strtok.c
)

set_target_properties(test-strtok PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strtok" COMMAND test-strtok)
