
include_guard(GLOBAL)

add_executable(test-getlogin_r)

target_link_libraries(test-getlogin_r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getlogin_r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getlogin_r.c
)

set_target_properties(test-getlogin_r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getlogin_r" COMMAND test-getlogin_r)
