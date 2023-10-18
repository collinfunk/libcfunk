
include_guard(GLOBAL)

add_executable(test-md5)

target_link_libraries(test-md5 PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-md5 PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-md5.c
)

set_target_properties(test-md5 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
