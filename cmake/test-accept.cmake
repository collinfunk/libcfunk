
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/netinet-in-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sockets.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/memset.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)

add_executable(test-accept)

target_link_libraries(test-accept PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-accept PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-accept.c
)

set_target_properties(test-accept PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-accept" COMMAND test-accept)
