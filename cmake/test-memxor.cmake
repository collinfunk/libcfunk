
include_guard(GLOBAL)

add_executable(test-memxor)

target_link_libraries(test-memxor PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-memxor PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-memxor.c
)

set_target_properties(test-memxor PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
