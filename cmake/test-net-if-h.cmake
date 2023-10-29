
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-net-if-h)

target_link_libraries(test-net-if-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-net-if-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-net-if-h.c
)

set_target_properties(test-net-if-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-net-if-h" COMMAND test-net-if-h)
