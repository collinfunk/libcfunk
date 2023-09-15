
include_guard(GLOBAL)

add_executable(test-filename-strip-slashes)

target_link_libraries(test-filename-strip-slashes PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-filename-strip-slashes PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-filename-strip-slashes.c
)

set_target_properties(test-filename-strip-slashes PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
