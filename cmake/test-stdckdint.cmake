
include_guard(GLOBAL)

add_executable(test-stdckdint)

target_link_libraries(test-stdckdint PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdckdint PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdckdint.c
)

set_target_properties(test-stdckdint PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stdckdint" COMMAND test-stdckdint)
