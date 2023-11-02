
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-spawn-h)

target_link_libraries(test-spawn-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-spawn-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-spawn-h.c
)

set_target_properties(test-spawn-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-spawn-h" COMMAND test-spawn-h)
