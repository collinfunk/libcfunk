
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)

add_executable(test-fstat)

target_link_libraries(test-fstat PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fstat PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fstat.c
)

set_target_properties(test-fstat PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
