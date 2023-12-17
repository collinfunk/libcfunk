
include_guard(GLOBAL)

add_executable(test-atoll)

target_link_libraries(test-atoll PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-atoll PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-atoll.c
)

set_target_properties(test-atoll PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-atoll" COMMAND test-atoll)
