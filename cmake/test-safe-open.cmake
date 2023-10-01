
include_guard(GLOBAL)

add_executable(test-safe-open)

target_link_libraries(test-safe-open PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-safe-open PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-safe-open.c
)

set_target_properties(test-safe-open PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
