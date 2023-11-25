
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-wchar-h)

target_link_libraries(test-wchar-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wchar-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wchar-h.c
)

set_target_properties(test-wchar-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wchar-h" COMMAND test-wchar-h)
