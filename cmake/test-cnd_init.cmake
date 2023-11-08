
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/cnd_destroy.cmake)

add_executable(test-cnd_init)

target_link_libraries(test-cnd_init PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-cnd_init PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-cnd_init.c
)

set_target_properties(test-cnd_init PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-cnd_init" COMMAND test-cnd_init)
