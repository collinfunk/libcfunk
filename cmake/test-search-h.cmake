
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-search-h)

target_link_libraries(test-search-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-search-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-search-h.c
)

set_target_properties(test-search-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-search-h" COMMAND test-search-h)
