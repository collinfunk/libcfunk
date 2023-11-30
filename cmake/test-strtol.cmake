
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)

add_executable(test-strtol)

target_link_libraries(test-strtol PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strtol PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strtol.c
)

set_target_properties(test-strtol PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strtol" COMMAND test-strtol)
