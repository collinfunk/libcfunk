
include_guard(GLOBAL)

add_executable(test-sched_yield)

target_link_libraries(test-sched_yield PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sched_yield PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sched_yield.c
)

set_target_properties(test-sched_yield PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sched_yield" COMMAND test-sched_yield)
