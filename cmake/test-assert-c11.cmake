
include_guard(GLOBAL)

add_executable(test-assert-c11)

target_link_libraries(test-assert-c11 PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-assert-c11 PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-assert-c11.c
)

set_target_properties(test-assert-c11 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-assert-c11" COMMAND test-assert-c11)
