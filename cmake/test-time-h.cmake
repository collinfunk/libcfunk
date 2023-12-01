
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-time-h)

target_link_libraries(test-time-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-time-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-time-h.c
)

set_target_properties(test-time-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-time-h" COMMAND test-time-h)
