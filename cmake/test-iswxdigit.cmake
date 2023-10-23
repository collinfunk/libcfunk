
include_guard(GLOBAL)

add_executable(test-iswxdigit)

target_link_libraries(test-iswxdigit PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswxdigit PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswxdigit.c
)

set_target_properties(test-iswxdigit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswxdigit" COMMAND test-iswxdigit)
