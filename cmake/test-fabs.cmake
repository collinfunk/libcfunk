
include_guard(GLOBAL)

add_executable(test-fabs)

target_link_libraries(test-fabs PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fabs PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fabs.c
)

set_target_properties(test-fabs PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fabs" COMMAND test-fabs)
