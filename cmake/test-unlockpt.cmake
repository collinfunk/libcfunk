
include_guard(GLOBAL)

add_executable(test-unlockpt)

target_link_libraries(test-unlockpt PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-unlockpt PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-unlockpt.c
)

set_target_properties(test-unlockpt PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
