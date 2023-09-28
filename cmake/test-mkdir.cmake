
include_guard(GLOBAL)

add_executable(test-mkdir)

target_link_libraries(test-mkdir PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-mkdir PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-mkdir.c
)

set_target_properties(test-mkdir PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
