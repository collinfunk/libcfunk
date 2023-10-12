
include_guard(GLOBAL)

add_executable(test-__fwritable)

target_link_libraries(test-__fwritable PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-__fwritable PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-__fwritable.c
)

set_target_properties(test-__fwritable PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
