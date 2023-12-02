
include_guard(GLOBAL)

add_executable(test-wcspbrk)

target_link_libraries(test-wcspbrk PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wcspbrk PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wcspbrk.c
)

set_target_properties(test-wcspbrk PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wcspbrk" COMMAND test-wcspbrk)
