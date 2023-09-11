
include_guard(GLOBAL)

add_executable(test-getrandom)

target_link_libraries(test-getrandom PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getrandom PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getrandom.c
)

set_target_properties(test-getrandom PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
