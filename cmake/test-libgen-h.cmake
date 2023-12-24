
include_guard(GLOBAL)

add_executable(test-libgen-h)

target_link_libraries(test-libgen-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-libgen-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-libgen-h.c
)

set_target_properties(test-libgen-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-libgen-h" COMMAND test-libgen-h)
