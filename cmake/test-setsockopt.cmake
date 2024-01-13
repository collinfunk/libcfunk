
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sockets.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)

add_executable(test-setsockopt)

target_link_libraries(test-setsockopt PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-setsockopt PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-setsockopt.c
)

set_target_properties(test-setsockopt PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-setsockopt" COMMAND test-setsockopt)
