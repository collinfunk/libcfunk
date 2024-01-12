
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/if_nameindex.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/if_freenameindex.cmake)

add_executable(test-if_nametoindex)

target_link_libraries(test-if_nametoindex PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-if_nametoindex PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-if_nametoindex.c
)

set_target_properties(test-if_nametoindex PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-if_nametoindex" COMMAND test-if_nametoindex)
