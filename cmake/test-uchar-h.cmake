
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-uchar-h)

target_link_libraries(test-uchar-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-uchar-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-uchar-h.c
)

set_target_properties(test-uchar-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-uchar-h" COMMAND test-uchar-h)
