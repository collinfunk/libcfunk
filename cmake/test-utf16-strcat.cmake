
include_guard(GLOBAL)

add_executable(test-utf16-strcat)

target_link_libraries(test-utf16-strcat PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-utf16-strcat PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-utf16-strcat.c
)

set_target_properties(test-utf16-strcat PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-utf16-strcat" COMMAND test-utf16-strcat)
