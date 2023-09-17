
include_guard(GLOBAL)

add_executable(test-ttyname-r)

target_link_libraries(test-ttyname-r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ttyname-r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ttyname-r.c
)

set_target_properties(test-ttyname-r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
