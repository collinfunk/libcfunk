
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/symlink.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)

add_executable(test-stat)

target_link_libraries(test-stat PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stat PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stat.c
)

set_target_properties(test-stat PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
