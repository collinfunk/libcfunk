
include_guard(GLOBAL)

add_executable(test-malloc)

target_link_libraries(test-malloc PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-malloc PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-malloc.c
)

set_target_properties(test-malloc PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
