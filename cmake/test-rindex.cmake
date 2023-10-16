
include_guard(GLOBAL)

add_executable(test-rindex)

target_link_libraries(test-rindex PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-rindex PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-rindex.c
)

set_target_properties(test-rindex PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
