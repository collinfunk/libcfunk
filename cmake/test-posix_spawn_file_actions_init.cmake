
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/posix_spawn_file_actions_destroy.cmake)

add_executable(test-posix_spawn_file_actions_init)

target_link_libraries(test-posix_spawn_file_actions_init PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-posix_spawn_file_actions_init PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-posix_spawn_file_actions_init.c
)

set_target_properties(test-posix_spawn_file_actions_init PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-posix_spawn_file_actions_init" COMMAND test-posix_spawn_file_actions_init)
