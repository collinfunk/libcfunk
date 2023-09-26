
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/_Exit.cmake)

add_executable(test-atexit)

target_link_libraries(test-atexit PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-atexit PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-atexit.c
)

set_target_properties(test-atexit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
