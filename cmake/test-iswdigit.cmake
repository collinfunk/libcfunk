
include_guard(GLOBAL)

add_executable(test-iswdigit)

target_link_libraries(test-iswdigit PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswdigit PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswdigit.c
)

set_target_properties(test-iswdigit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswdigit" COMMAND test-iswdigit)
