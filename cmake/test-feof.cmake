
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)

add_executable(test-feof)

target_link_libraries(test-feof PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-feof PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-feof.c
)

set_target_properties(test-feof PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-feof" COMMAND test-feof)
