
include_guard(GLOBAL)

add_executable(test-cpu-count)

target_link_libraries(test-cpu-count PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-cpu-count PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-cpu-count.c
)

set_target_properties(test-cpu-count PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
