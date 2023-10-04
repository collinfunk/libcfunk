
include_guard(GLOBAL)

add_executable(test-pipe)

target_link_libraries(test-pipe PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-pipe PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-pipe.c
)

set_target_properties(test-pipe PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
