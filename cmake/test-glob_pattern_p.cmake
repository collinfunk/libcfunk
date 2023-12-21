
include_guard(GLOBAL)

add_executable(test-glob_pattern_p)

target_link_libraries(test-glob_pattern_p PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-glob_pattern_p PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-glob_pattern_p.c
)

set_target_properties(test-glob_pattern_p PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-glob_pattern_p" COMMAND test-glob_pattern_p)
