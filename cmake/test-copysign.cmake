
include_guard(GLOBAL)

add_executable(test-copysign)

target_link_libraries(test-copysign PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-copysign PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-copysign.c
)

set_target_properties(test-copysign PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-copysign" COMMAND test-copysign)
