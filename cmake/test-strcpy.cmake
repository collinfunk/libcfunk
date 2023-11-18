
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memcmp.cmake)

add_executable(test-strcpy)

target_link_libraries(test-strcpy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strcpy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strcpy.c
)

set_target_properties(test-strcpy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strcpy" COMMAND test-strcpy)
