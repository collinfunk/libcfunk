
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)

add_executable(test-open)

target_link_libraries(test-open PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-open PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-open.c
)

set_target_properties(test-open PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-open" COMMAND test-open)
