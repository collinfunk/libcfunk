
include_guard(GLOBAL)

add_executable(test-byteswap-h)

target_link_libraries(test-byteswap-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-byteswap-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-byteswap-h.c
)

set_target_properties(test-byteswap-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-byteswap-h" COMMAND test-byteswap-h)
