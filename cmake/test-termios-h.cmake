
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-termios-h)

target_link_libraries(test-termios-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-termios-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-termios-h.c
)

set_target_properties(test-termios-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
