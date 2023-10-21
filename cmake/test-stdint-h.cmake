
include_guard(GLOBAL)

add_executable(test-stdint-h)

target_link_libraries(test-stdint-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdint-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdint-h.c
)

set_target_properties(test-stdint-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stdint-h" COMMAND test-stdint-h)
