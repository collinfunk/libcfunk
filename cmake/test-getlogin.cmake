
include_guard(GLOBAL)

add_executable(test-getlogin)

target_link_libraries(test-getlogin PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getlogin PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getlogin.c
)

set_target_properties(test-getlogin PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
