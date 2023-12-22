
include_guard(GLOBAL)

add_executable(test-l64a)

target_link_libraries(test-l64a PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-l64a PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-l64a.c
)

set_target_properties(test-l64a PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-l64a" COMMAND test-l64a)
