
include_guard(GLOBAL)

add_executable(test-atoi)

target_link_libraries(test-atoi PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-atoi PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-atoi.c
)

set_target_properties(test-atoi PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-atoi" COMMAND test-atoi)
