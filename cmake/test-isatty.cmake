
include_guard(GLOBAL)

add_executable(test-isatty)

target_link_libraries(test-isatty PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-isatty PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-isatty.c
)

set_target_properties(test-isatty PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
