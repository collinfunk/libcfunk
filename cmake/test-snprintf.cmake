
include_guard(GLOBAL)

add_executable(test-snprintf)

target_link_libraries(test-snprintf PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-snprintf PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-snprintf.c
)

set_target_properties(test-snprintf PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-snprintf" COMMAND test-snprintf)
