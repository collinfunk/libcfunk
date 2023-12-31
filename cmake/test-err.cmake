
include_guard(GLOBAL)

add_executable(test-err)

target_link_libraries(test-err PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-err PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-err.c
)

set_target_properties(test-err PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-err" COMMAND test-err)
