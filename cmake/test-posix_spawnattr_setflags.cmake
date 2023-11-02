
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/posix_spawnattr_init.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/posix_spawnattr_destroy.cmake)

add_executable(test-posix_spawnattr_setflags)

target_link_libraries(test-posix_spawnattr_setflags PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-posix_spawnattr_setflags PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-posix_spawnattr_setflags.c
)

set_target_properties(test-posix_spawnattr_setflags PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-posix_spawnattr_setflags" COMMAND test-posix_spawnattr_setflags)
