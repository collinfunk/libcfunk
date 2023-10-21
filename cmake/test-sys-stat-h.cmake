
include_guard(GLOBAL)

add_executable(test-sys-stat-h)

target_link_libraries(test-sys-stat-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-stat-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-stat-h.c
)

set_target_properties(test-sys-stat-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sys-stat-h" COMMAND test-sys-stat-h)
