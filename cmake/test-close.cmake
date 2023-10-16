
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)

add_executable(test-close)

target_link_libraries(test-close PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-close PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-close.c
)

set_target_properties(test-close PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
