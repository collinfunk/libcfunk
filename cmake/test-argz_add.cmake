
include_guard(GLOBAL)

add_executable(test-argz_add)

target_link_libraries(test-argz_add PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-argz_add PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-argz_add.c
)

set_target_properties(test-argz_add PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-argz_add" COMMAND test-argz_add)
