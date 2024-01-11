
include_guard(GLOBAL)

add_executable(test-fork)

target_link_libraries(test-fork PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fork PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fork.c
)

set_target_properties(test-fork PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fork" COMMAND test-fork)
