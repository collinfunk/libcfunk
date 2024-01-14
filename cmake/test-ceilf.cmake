
include_guard(GLOBAL)

add_executable(test-ceilf)

target_link_libraries(test-ceilf PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ceilf PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ceilf.c
)

set_target_properties(test-ceilf PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ceilf" COMMAND test-ceilf)
