
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)

add_executable(test-chmod)

target_link_libraries(test-chmod PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-chmod PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-chmod.c
)

set_target_properties(test-chmod PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-chmod" COMMAND test-chmod)
