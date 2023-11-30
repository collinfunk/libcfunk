
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)

add_executable(test-strtoul)

target_link_libraries(test-strtoul PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strtoul PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strtoul.c
)

set_target_properties(test-strtoul PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strtoul" COMMAND test-strtoul)
