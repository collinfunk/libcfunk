
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sockets.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/netinet-in-h.cmake)

add_executable(test-connect)

target_link_libraries(test-connect PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-connect PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-connect.c
)

set_target_properties(test-connect PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
