
include_guard(GLOBAL)

add_executable(test-_Exit)

target_link_libraries(test-_Exit PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-_Exit PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-_Exit.c
)

set_target_properties(test-_Exit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
