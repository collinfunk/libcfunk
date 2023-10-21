
include_guard(GLOBAL)

add_executable(test-__fpending)

target_link_libraries(test-__fpending PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-__fpending PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-__fpending.c
)

set_target_properties(test-__fpending PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-__fpending" COMMAND test-__fpending)
