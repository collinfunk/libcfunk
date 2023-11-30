
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)

add_executable(test-strtoll)

target_link_libraries(test-strtoll PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strtoll PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strtoll.c
)

set_target_properties(test-strtoll PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strtoll" COMMAND test-strtoll)
