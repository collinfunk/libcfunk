
include_guard(GLOBAL)

add_executable(test-dprintf)

target_link_libraries(test-dprintf PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-dprintf PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-dprintf.c
)

set_target_properties(test-dprintf PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-dprintf" COMMAND test-dprintf)
