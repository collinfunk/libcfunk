
include_guard(GLOBAL)

add_executable(test-alignof)

target_link_libraries(test-alignof PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-alignof PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-alignof.c
)

set_target_properties(test-alignof PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
