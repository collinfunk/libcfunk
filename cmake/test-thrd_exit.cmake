
include_guard(GLOBAL)

add_executable(test-thrd_exit)

target_link_libraries(test-thrd_exit PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-thrd_exit PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-thrd_exit.c
)

set_target_properties(test-thrd_exit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-thrd_exit" COMMAND test-thrd_exit)
