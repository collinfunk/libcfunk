
include_guard(GLOBAL)

add_executable(test-ttyname_r)

target_link_libraries(test-ttyname_r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ttyname_r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ttyname_r.c
)

set_target_properties(test-ttyname_r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ttyname_r" COMMAND test-ttyname_r)
