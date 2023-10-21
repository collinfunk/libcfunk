
include_guard(GLOBAL)

add_executable(test-getlogin-r)

target_link_libraries(test-getlogin-r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getlogin-r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getlogin-r.c
)

set_target_properties(test-getlogin-r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getlogin-r" COMMAND test-getlogin-r)
