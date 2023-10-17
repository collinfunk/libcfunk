
include_guard(GLOBAL)

add_executable(test-tzset)

target_link_libraries(test-tzset PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-tzset PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-tzset.c
)

set_target_properties(test-tzset PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
