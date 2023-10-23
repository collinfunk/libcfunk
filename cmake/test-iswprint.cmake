
include_guard(GLOBAL)

add_executable(test-iswprint)

target_link_libraries(test-iswprint PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswprint PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswprint.c
)

set_target_properties(test-iswprint PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswprint" COMMAND test-iswprint)
