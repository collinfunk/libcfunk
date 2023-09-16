
include_guard(GLOBAL)

add_executable(test-alignas)

target_link_libraries(test-alignas PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-alignas PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-alignas.c
)

set_target_properties(test-alignas PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
