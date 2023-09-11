
include_guard(GLOBAL)

add_executable(test-dysize)

target_link_libraries(test-dysize PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-dysize PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-dysize.c
)

set_target_properties(test-dysize PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
