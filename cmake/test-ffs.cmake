
include_guard(GLOBAL)

add_executable(test-ffs)

target_link_libraries(test-ffs PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ffs PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ffs.c
)

set_target_properties(test-ffs PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ffs" COMMAND test-ffs)
