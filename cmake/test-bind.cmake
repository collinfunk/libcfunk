
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/netinet-in-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/arpa-inet-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/inet_pton.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sockets.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)

add_executable(test-bind)

target_link_libraries(test-bind PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-bind PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-bind.c
)

set_target_properties(test-bind PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-bind" COMMAND test-bind)
