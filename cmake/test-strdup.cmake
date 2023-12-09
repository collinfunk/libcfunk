
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-strdup)

target_link_libraries(test-strdup PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strdup PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strdup.c
)

set_target_properties(test-strdup PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strdup" COMMAND test-strdup)
