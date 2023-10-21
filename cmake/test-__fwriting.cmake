
include_guard(GLOBAL)

add_executable(test-__fwriting)

target_link_libraries(test-__fwriting PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-__fwriting PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-__fwriting.c
)

set_target_properties(test-__fwriting PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-__fwriting" COMMAND test-__fwriting)
