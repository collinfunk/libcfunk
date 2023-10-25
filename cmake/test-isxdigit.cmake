
include_guard(GLOBAL)

add_executable(test-isxdigit)

target_link_libraries(test-isxdigit PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-isxdigit PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-isxdigit.c
)

set_target_properties(test-isxdigit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-isxdigit" COMMAND test-isxdigit)
