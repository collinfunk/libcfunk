
include_guard(GLOBAL)

add_executable(test-copysignf)

target_link_libraries(test-copysignf PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-copysignf PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-copysignf.c
)

set_target_properties(test-copysignf PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-copysignf" COMMAND test-copysignf)
