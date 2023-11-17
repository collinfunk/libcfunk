
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/inet_aton.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-inet_ntoa)

target_link_libraries(test-inet_ntoa PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-inet_ntoa PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-inet_ntoa.c
)

set_target_properties(test-inet_ntoa PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-inet_ntoa" COMMAND test-inet_ntoa)
