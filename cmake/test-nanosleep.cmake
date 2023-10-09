
include_guard(GLOBAL)

add_executable(test-nanosleep)

target_link_libraries(test-nanosleep PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-nanosleep PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-nanosleep.c
)

set_target_properties(test-nanosleep PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
