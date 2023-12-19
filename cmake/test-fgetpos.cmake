
include_guard(GLOBAL)

add_executable(test-fgetpos)

target_link_libraries(test-fgetpos PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fgetpos PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fgetpos.c
)

set_target_properties(test-fgetpos PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fgetpos" COMMAND test-fgetpos)
