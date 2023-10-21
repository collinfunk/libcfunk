
include_guard(GLOBAL)

add_executable(test-stat-timespec)

target_link_libraries(test-stat-timespec PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stat-timespec PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stat-timespec.c
)

set_target_properties(test-stat-timespec PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stat-timespec" COMMAND test-stat-timespec)
