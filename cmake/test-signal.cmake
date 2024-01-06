
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-signal)

target_link_libraries(test-signal PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-signal PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-signal.c
)

set_target_properties(test-signal PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-signal" COMMAND test-signal)
