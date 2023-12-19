
include_guard(GLOBAL)

add_executable(test-time)

target_link_libraries(test-time PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-time PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-time.c
)

set_target_properties(test-time PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-time" COMMAND test-time)
