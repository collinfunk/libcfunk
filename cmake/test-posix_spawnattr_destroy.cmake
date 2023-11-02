
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/posix_spawnattr_init.cmake)

add_executable(test-posix_spawnattr_destroy)

target_link_libraries(test-posix_spawnattr_destroy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-posix_spawnattr_destroy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-posix_spawnattr_destroy.c
)

set_target_properties(test-posix_spawnattr_destroy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-posix_spawnattr_destroy" COMMAND test-posix_spawnattr_destroy)
