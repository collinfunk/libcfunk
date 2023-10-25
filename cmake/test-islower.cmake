
include_guard(GLOBAL)

add_executable(test-islower)

target_link_libraries(test-islower PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-islower PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-islower.c
)

set_target_properties(test-islower PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-islower" COMMAND test-islower)
