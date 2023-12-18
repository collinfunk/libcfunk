
include_guard(GLOBAL)

add_executable(test-strtod)

target_link_libraries(test-strtod PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strtod PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strtod.c
)

set_target_properties(test-strtod PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strtod" COMMAND test-strtod)
