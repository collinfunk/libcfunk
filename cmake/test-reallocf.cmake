
include_guard(GLOBAL)

add_executable(test-reallocf)

target_link_libraries(test-reallocf PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-reallocf PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-reallocf.c
)

set_target_properties(test-reallocf PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-reallocf" COMMAND test-reallocf)
