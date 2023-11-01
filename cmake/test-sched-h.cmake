
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-sched-h)

target_link_libraries(test-sched-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sched-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sched-h.c
)

set_target_properties(test-sched-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sched-h" COMMAND test-sched-h)
