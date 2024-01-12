
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sockets.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)

add_executable(test-recv)

target_link_libraries(test-recv PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-recv PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-recv.c
)

set_target_properties(test-recv PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-recv" COMMAND test-recv)
