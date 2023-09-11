
include_guard(GLOBAL)

add_executable(test-timespec-get)

target_link_libraries(test-timespec-get PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-timespec-get PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-timespec-get.c
)

set_target_properties(test-timespec-get PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
