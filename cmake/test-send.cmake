
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sockets.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)

add_executable(test-send)

target_link_libraries(test-send PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-send PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-send.c
)

set_target_properties(test-send PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-send" COMMAND test-send)
