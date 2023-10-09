
include_guard(GLOBAL)

add_executable(test-gethostname)

target_link_libraries(test-gethostname PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-gethostname PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-gethostname.c
)

set_target_properties(test-gethostname PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
