
include_guard(GLOBAL)

add_executable(test-limits-h)

target_link_libraries(test-limits-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-limits-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-limits-h.c
)

set_target_properties(test-limits-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
