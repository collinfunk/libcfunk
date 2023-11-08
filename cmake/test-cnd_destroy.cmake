
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/cnd_init.cmake)

add_executable(test-cnd_destroy)

target_link_libraries(test-cnd_destroy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-cnd_destroy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-cnd_destroy.c
)

set_target_properties(test-cnd_destroy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-cnd_destroy" COMMAND test-cnd_destroy)
