
include_guard(GLOBAL)

add_executable(test-thrd_sleep)

target_link_libraries(test-thrd_sleep PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-thrd_sleep PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-thrd_sleep.c
)

set_target_properties(test-thrd_sleep PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-thrd_sleep" COMMAND test-thrd_sleep)
