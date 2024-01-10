
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-sys-msg-h)

target_link_libraries(test-sys-msg-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-msg-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-msg-h.c
)

set_target_properties(test-sys-msg-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sys-msg-h" COMMAND test-sys-msg-h)
