
include_guard(GLOBAL)

add_executable(test-sha1)

target_link_libraries(test-sha1 PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sha1 PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sha1.c
)

set_target_properties(test-sha1 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
