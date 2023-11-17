
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memcmp.cmake)

add_executable(test-inet_aton)

target_link_libraries(test-inet_aton PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-inet_aton PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-inet_aton.c
)

set_target_properties(test-inet_aton PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-inet_aton" COMMAND test-inet_aton)
