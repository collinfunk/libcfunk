
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-stdbit-h)

target_link_libraries(test-stdbit-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdbit-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdbit-h.c
)

set_target_properties(test-stdbit-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stdbit-h" COMMAND test-stdbit-h)
