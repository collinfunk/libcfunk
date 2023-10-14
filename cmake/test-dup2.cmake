
include_guard(GLOBAL)

add_executable(test-dup2)

target_link_libraries(test-dup2 PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-dup2 PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-dup2.c
)

set_target_properties(test-dup2 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
