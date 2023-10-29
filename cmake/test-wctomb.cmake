
include_guard(GLOBAL)

add_executable(test-wctomb)

target_link_libraries(test-wctomb PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wctomb PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wctomb.c
)

set_target_properties(test-wctomb PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wctomb" COMMAND test-wctomb)
