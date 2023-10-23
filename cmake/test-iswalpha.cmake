
include_guard(GLOBAL)

add_executable(test-iswalpha)

target_link_libraries(test-iswalpha PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswalpha PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswalpha.c
)

set_target_properties(test-iswalpha PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswalpha" COMMAND test-iswalpha)
