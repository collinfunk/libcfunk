
include_guard(GLOBAL)

add_executable(test-asprintf)

target_link_libraries(test-asprintf PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-asprintf PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-asprintf.c
)

set_target_properties(test-asprintf PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-asprintf" COMMAND test-asprintf)
