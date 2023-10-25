
include_guard(GLOBAL)

add_executable(test-wmemset)

target_link_libraries(test-wmemset PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wmemset PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wmemset.c
)

set_target_properties(test-wmemset PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wmemset" COMMAND test-wmemset)
