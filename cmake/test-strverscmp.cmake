
include_guard(GLOBAL)

add_executable(test-strverscmp)

target_link_libraries(test-strverscmp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strverscmp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strverscmp.c
)

set_target_properties(test-strverscmp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strverscmp" COMMAND test-strverscmp)
