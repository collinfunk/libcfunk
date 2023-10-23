
include_guard(GLOBAL)

add_executable(test-iswblank)

target_link_libraries(test-iswblank PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswblank PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswblank.c
)

set_target_properties(test-iswblank PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswblank" COMMAND test-iswblank)
