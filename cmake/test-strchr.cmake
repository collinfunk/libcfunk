
include_guard(GLOBAL)

add_executable(test-strchr)

target_link_libraries(test-strchr PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strchr PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strchr.c
)

set_target_properties(test-strchr PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
