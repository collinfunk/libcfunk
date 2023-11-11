
include_guard(GLOBAL)

add_executable(test-gmtime_r)

target_link_libraries(test-gmtime_r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-gmtime_r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-gmtime_r.c
)

set_target_properties(test-gmtime_r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-gmtime_r" COMMAND test-gmtime_r)
