
include_guard(GLOBAL)

add_executable(test-strrchr)

target_link_libraries(test-strrchr PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strrchr PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strrchr.c
)

set_target_properties(test-strrchr PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
