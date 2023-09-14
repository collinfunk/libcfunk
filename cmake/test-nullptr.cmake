
include_guard(GLOBAL)

add_executable(test-nullptr)

target_link_libraries(test-nullptr PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-nullptr PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-nullptr.c
)

set_target_properties(test-nullptr PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
