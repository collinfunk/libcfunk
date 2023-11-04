
include_guard(GLOBAL)

add_executable(test-ffsl)

target_link_libraries(test-ffsl PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ffsl PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ffsl.c
)

set_target_properties(test-ffsl PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ffsl" COMMAND test-ffsl)
