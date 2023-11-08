
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/mtx_init.cmake)

add_executable(test-mtx_destroy)

target_link_libraries(test-mtx_destroy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-mtx_destroy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-mtx_destroy.c
)

set_target_properties(test-mtx_destroy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-mtx_destroy" COMMAND test-mtx_destroy)
