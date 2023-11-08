
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/mtx_destroy.cmake)

add_executable(test-mtx_init)

target_link_libraries(test-mtx_init PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-mtx_init PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-mtx_init.c
)

set_target_properties(test-mtx_init PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-mtx_init" COMMAND test-mtx_init)
