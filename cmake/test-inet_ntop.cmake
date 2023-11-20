
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-inet_ntop)

target_link_libraries(test-inet_ntop PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-inet_ntop PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-inet_ntop.c
)

set_target_properties(test-inet_ntop PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-inet_ntop" COMMAND test-inet_ntop)
