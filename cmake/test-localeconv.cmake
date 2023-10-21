
include_guard(GLOBAL)

add_executable(test-localeconv)

target_link_libraries(test-localeconv PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-localeconv PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-localeconv.c
)

set_target_properties(test-localeconv PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-localeconv" COMMAND test-localeconv)
