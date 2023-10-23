
include_guard(GLOBAL)

add_executable(test-iswpunct)

target_link_libraries(test-iswpunct PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswpunct PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswpunct.c
)

set_target_properties(test-iswpunct PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswpunct" COMMAND test-iswpunct)
