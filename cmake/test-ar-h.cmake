
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-ar-h)

target_link_libraries(test-ar-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ar-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ar-h.c
)

set_target_properties(test-ar-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ar-h" COMMAND test-ar-h)
