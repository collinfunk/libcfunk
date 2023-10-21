
include_guard(GLOBAL)

add_executable(test-_Alignas)

target_link_libraries(test-_Alignas PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-_Alignas PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-_Alignas.c
)

set_target_properties(test-_Alignas PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-_Alignas" COMMAND test-_Alignas)
