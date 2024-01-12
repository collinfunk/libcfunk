
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/if_nameindex.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/if_freenameindex.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-if_indextoname)

target_link_libraries(test-if_indextoname PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-if_indextoname PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-if_indextoname.c
)

set_target_properties(test-if_indextoname PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-if_indextoname" COMMAND test-if_indextoname)
