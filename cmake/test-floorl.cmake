
include_guard(GLOBAL)

add_executable(test-floorl)

target_link_libraries(test-floorl PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-floorl PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-floorl.c
)

set_target_properties(test-floorl PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-floorl" COMMAND test-floorl)
