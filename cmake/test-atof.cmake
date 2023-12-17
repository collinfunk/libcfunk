
include_guard(GLOBAL)

add_executable(test-atof)

target_link_libraries(test-atof PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-atof PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-atof.c
)

set_target_properties(test-atof PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-atof" COMMAND test-atof)
