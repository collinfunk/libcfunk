
include_guard(GLOBAL)

add_executable(test-__fpurge)

target_link_libraries(test-__fpurge PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-__fpurge PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-__fpurge.c
)

set_target_properties(test-__fpurge PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-__fpurge" COMMAND test-__fpurge)
