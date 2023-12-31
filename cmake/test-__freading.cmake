
include_guard(GLOBAL)

add_executable(test-__freading)

target_link_libraries(test-__freading PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-__freading PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-__freading.c
)

set_target_properties(test-__freading PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-__freading" COMMAND test-__freading)
