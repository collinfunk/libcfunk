
include_guard(GLOBAL)

add_executable(test-index)

target_link_libraries(test-index PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-index PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-index.c
)

set_target_properties(test-index PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-index" COMMAND test-index)
