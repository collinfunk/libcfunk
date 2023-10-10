
include_guard(GLOBAL)

add_executable(test-signal-h)

target_link_libraries(test-signal-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-signal-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-signal-h.c
)

set_target_properties(test-signal-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
