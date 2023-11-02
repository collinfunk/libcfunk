
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/posix_spawnattr_init.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/posix_spawnattr_destroy.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/posix_spawnattr_getschedparam.cmake)

add_executable(test-posix_spawnattr_setschedparam)

target_link_libraries(test-posix_spawnattr_setschedparam PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-posix_spawnattr_setschedparam PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-posix_spawnattr_setschedparam.c
)

set_target_properties(test-posix_spawnattr_setschedparam PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-posix_spawnattr_setschedparam" COMMAND test-posix_spawnattr_setschedparam)
