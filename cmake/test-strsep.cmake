
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-strsep)

target_link_libraries(test-strsep PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strsep PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strsep.c
)

set_target_properties(test-strsep PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strsep" COMMAND test-strsep)
