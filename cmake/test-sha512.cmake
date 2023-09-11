
include_guard(GLOBAL)

add_executable(test-sha512)

target_link_libraries(test-sha512 PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sha512 PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sha512.c
)

set_target_properties(test-sha512 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
