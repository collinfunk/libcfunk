
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/posix_spawn_file_actions_init.cmake)

add_executable(test-posix_spawn_file_actions_destroy)

target_link_libraries(test-posix_spawn_file_actions_destroy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-posix_spawn_file_actions_destroy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-posix_spawn_file_actions_destroy.c
)

set_target_properties(test-posix_spawn_file_actions_destroy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-posix_spawn_file_actions_destroy" COMMAND test-posix_spawn_file_actions_destroy)
