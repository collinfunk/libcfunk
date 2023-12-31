
include_guard(GLOBAL)

add_executable(test-bswap)

target_link_libraries(test-bswap PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-bswap PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-bswap.c
)

set_target_properties(test-bswap PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-bswap" COMMAND test-bswap)
