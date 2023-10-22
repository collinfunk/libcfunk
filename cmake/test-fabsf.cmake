
include_guard(GLOBAL)

add_executable(test-fabsf)

target_link_libraries(test-fabsf PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fabsf PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fabsf.c
)

set_target_properties(test-fabsf PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fabsf" COMMAND test-fabsf)
