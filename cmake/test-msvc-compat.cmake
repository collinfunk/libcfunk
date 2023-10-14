
include_guard(GLOBAL)

add_executable(test-msvc-compat)

target_link_libraries(test-msvc-compat PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-msvc-compat PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-msvc-compat.c
)

set_target_properties(test-msvc-compat PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
