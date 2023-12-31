
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-poll-h)

target_link_libraries(test-poll-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-poll-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-poll-h.c
)

set_target_properties(test-poll-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-poll-h" COMMAND test-poll-h)
