
include_guard(GLOBAL)

add_executable(test-circular-shift)

target_link_libraries(test-circular-shift PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-circular-shift PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-circular-shift.c
)

set_target_properties(test-circular-shift PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
