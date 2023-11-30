
include_guard(GLOBAL)

add_executable(test-strtoimax)

target_link_libraries(test-strtoimax PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strtoimax PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strtoimax.c
)

set_target_properties(test-strtoimax PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strtoimax" COMMAND test-strtoimax)
