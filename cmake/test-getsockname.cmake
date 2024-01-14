
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/netinet-in-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sockets.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)

add_executable(test-getsockname)

target_link_libraries(test-getsockname PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getsockname PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getsockname.c
)

set_target_properties(test-getsockname PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getsockname" COMMAND test-getsockname)
