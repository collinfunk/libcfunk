
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/if_freenameindex.cmake)

add_executable(test-if_nameindex)

target_link_libraries(test-if_nameindex PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-if_nameindex PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-if_nameindex.c
)

set_target_properties(test-if_nameindex PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-if_nameindex" COMMAND test-if_nameindex)
