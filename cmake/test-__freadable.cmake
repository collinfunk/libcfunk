
include_guard(GLOBAL)

add_executable(test-__freadable)

target_link_libraries(test-__freadable PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-__freadable PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-__freadable.c
)

set_target_properties(test-__freadable PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
