
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)

add_executable(test-strtoull)

target_link_libraries(test-strtoull PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strtoull PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strtoull.c
)

set_target_properties(test-strtoull PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strtoull" COMMAND test-strtoull)
