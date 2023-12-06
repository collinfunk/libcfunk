
include_guard(GLOBAL)

add_executable(test-llabs)

target_link_libraries(test-llabs PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-llabs PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-llabs.c
)

set_target_properties(test-llabs PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-llabs" COMMAND test-llabs)
