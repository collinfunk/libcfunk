
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/environ.cmake)

add_executable(test-posix_spawn1)

target_link_libraries(test-posix_spawn1 PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-posix_spawn1 PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-posix_spawn1.c
)

set_target_properties(test-posix_spawn1 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-posix_spawn1" COMMAND test-posix_spawn1)
