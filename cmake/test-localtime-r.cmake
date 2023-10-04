
include_guard(GLOBAL)

add_executable(test-localtime-r)

target_link_libraries(test-localtime-r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-localtime-r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-localtime-r.c
)

set_target_properties(test-localtime-r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
