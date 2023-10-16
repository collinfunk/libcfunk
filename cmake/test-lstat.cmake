
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/symlink.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)

add_executable(test-lstat)

target_link_libraries(test-lstat PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-lstat PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-lstat.c
)

set_target_properties(test-lstat PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
