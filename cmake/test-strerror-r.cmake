
include_guard(GLOBAL)

add_executable(test-strerror-r)

target_link_libraries(test-strerror-r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strerror-r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strerror-r.c
)

set_target_properties(test-strerror-r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
