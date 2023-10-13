
include_guard(GLOBAL)

add_executable(test-fsync)

target_link_libraries(test-fsync PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fsync PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fsync.c
)

set_target_properties(test-fsync PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
