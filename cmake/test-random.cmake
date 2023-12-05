
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memcmp.cmake)

add_executable(test-random)

target_link_libraries(test-random PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-random PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-random.c
)

set_target_properties(test-random PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-random" COMMAND test-random)
