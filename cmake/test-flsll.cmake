
include_guard(GLOBAL)

add_executable(test-flsll)

target_link_libraries(test-flsll PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-flsll PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-flsll.c
)

set_target_properties(test-flsll PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-flsll" COMMAND test-flsll)
