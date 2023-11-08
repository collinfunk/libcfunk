
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/test-thrd_equal.cmake)

add_executable(test-thrd_equal)

target_link_libraries(test-thrd_equal PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-thrd_equal PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-thrd_equal.c
)

set_target_properties(test-thrd_equal PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-thrd_equal" COMMAND test-thrd_equal)
