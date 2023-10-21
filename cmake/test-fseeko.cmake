
include_guard(GLOBAL)

add_executable(test-fseeko)

target_link_libraries(test-fseeko PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fseeko PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fseeko.c
)

set_target_properties(test-fseeko PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fseeko" COMMAND test-fseeko)
