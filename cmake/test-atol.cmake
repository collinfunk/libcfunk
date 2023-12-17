
include_guard(GLOBAL)

add_executable(test-atol)

target_link_libraries(test-atol PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-atol PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-atol.c
)

set_target_properties(test-atol PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-atol" COMMAND test-atol)
