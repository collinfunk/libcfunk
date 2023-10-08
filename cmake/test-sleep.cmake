
include_guard(GLOBAL)

add_executable(test-sleep)

target_link_libraries(test-sleep PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sleep PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sleep.c
)

set_target_properties(test-sleep PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
