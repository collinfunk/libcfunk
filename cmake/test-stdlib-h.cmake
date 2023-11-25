
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-stdlib-h)

target_link_libraries(test-stdlib-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdlib-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdlib-h.c
)

set_target_properties(test-stdlib-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stdlib-h" COMMAND test-stdlib-h)
