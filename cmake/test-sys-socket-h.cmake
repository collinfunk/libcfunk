
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-sys-socket-h)

target_link_libraries(test-sys-socket-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-socket-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-socket-h.c
)

set_target_properties(test-sys-socket-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sys-socket-h" COMMAND test-sys-socket-h)
