
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memcmp.cmake)

add_executable(test-memcpy)

target_link_libraries(test-memcpy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-memcpy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-memcpy.c
)

set_target_properties(test-memcpy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-memcpy" COMMAND test-memcpy)
