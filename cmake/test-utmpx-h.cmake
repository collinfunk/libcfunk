
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-utmpx-h)

target_link_libraries(test-utmpx-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-utmpx-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-utmpx-h.c
)

set_target_properties(test-utmpx-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-utmpx-h" COMMAND test-utmpx-h)
