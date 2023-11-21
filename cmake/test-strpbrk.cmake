
include_guard(GLOBAL)

add_executable(test-strpbrk)

target_link_libraries(test-strpbrk PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strpbrk PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strpbrk.c
)

set_target_properties(test-strpbrk PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strpbrk" COMMAND test-strpbrk)
