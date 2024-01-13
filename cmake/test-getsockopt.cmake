
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sockets.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)

add_executable(test-getsockopt)

target_link_libraries(test-getsockopt PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getsockopt PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getsockopt.c
)

set_target_properties(test-getsockopt PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getsockopt" COMMAND test-getsockopt)
