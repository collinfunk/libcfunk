
include_guard(GLOBAL)

add_executable(test-ceill)

target_link_libraries(test-ceill PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ceill PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ceill.c
)

set_target_properties(test-ceill PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ceill" COMMAND test-ceill)
