
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memcmp.cmake)

add_executable(test-swab)

target_link_libraries(test-swab PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-swab PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-swab.c
)

set_target_properties(test-swab PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-swab" COMMAND test-swab)
