
include_guard(GLOBAL)

add_executable(test-isblank)

target_link_libraries(test-isblank PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-isblank PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-isblank.c
)

set_target_properties(test-isblank PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-isblank" COMMAND test-isblank)
