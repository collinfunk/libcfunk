
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-strtok_r)

target_link_libraries(test-strtok_r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strtok_r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strtok_r.c
)

set_target_properties(test-strtok_r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strtok_r" COMMAND test-strtok_r)
