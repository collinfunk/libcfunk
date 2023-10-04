
include_guard(GLOBAL)

add_executable(test-gmtime-r)

target_link_libraries(test-gmtime-r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-gmtime-r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-gmtime-r.c
)

set_target_properties(test-gmtime-r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
