
include_guard(GLOBAL)

add_executable(test-max)

target_link_libraries(test-max PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-max PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-max.c
)

set_target_properties(test-max PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-max" COMMAND test-max)
