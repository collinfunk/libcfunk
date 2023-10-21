
include_guard(GLOBAL)

add_executable(test-flock)

target_link_libraries(test-flock PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-flock PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-flock.c
)

set_target_properties(test-flock PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-flock" COMMAND test-flock)
