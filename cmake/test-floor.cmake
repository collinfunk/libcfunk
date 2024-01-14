
include_guard(GLOBAL)

add_executable(test-floor)

target_link_libraries(test-floor PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-floor PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-floor.c
)

set_target_properties(test-floor PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-floor" COMMAND test-floor)
