
include_guard(GLOBAL)

add_executable(test-localtime_r)

target_link_libraries(test-localtime_r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-localtime_r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-localtime_r.c
)

set_target_properties(test-localtime_r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-localtime_r" COMMAND test-localtime_r)
