
include_guard(GLOBAL)

add_executable(test-daemon)

target_link_libraries(test-daemon PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-daemon PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-daemon.c
)

set_target_properties(test-daemon PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
