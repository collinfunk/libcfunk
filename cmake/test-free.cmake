
include_guard(GLOBAL)

add_executable(test-free)

target_link_libraries(test-free PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-free PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-free.c
)

set_target_properties(test-free PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
