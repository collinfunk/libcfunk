
include_guard(GLOBAL)

add_executable(test-stdbool-h)

target_link_libraries(test-stdbool-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdbool-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdbool-h.c
)

set_target_properties(test-stdbool-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
