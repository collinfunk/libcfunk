
include_guard(GLOBAL)

add_executable(test-root-uid)

target_link_libraries(test-root-uid PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-root-uid PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-root-uid.c
)

set_target_properties(test-root-uid PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
