
include_guard(GLOBAL)

add_executable(test-argz_extract)

target_link_libraries(test-argz_extract PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-argz_extract PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-argz_extract.c
)

set_target_properties(test-argz_extract PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-argz_extract" COMMAND test-argz_extract)
