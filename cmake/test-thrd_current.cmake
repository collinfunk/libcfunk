
include_guard(GLOBAL)

add_executable(test-thrd_current)

target_link_libraries(test-thrd_current PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-thrd_current PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-thrd_current.c
)

set_target_properties(test-thrd_current PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-thrd_current" COMMAND test-thrd_current)
