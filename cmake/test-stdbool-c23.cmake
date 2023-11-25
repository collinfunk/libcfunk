
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-stdbool-c23)

target_link_libraries(test-stdbool-c23 PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdbool-c23 PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdbool-c23.c
)

set_target_properties(test-stdbool-c23 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stdbool-c23" COMMAND test-stdbool-c23)
