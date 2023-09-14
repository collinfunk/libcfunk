
include_guard(GLOBAL)

add_executable(test-min)

target_link_libraries(test-min PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-min PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-min.c
)

set_target_properties(test-min PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
