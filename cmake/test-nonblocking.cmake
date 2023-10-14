
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/pipe.cmake)

add_executable(test-nonblocking)

target_link_libraries(test-nonblocking PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-nonblocking PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-nonblocking.c
)

set_target_properties(test-nonblocking PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
