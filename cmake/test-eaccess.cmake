
include_guard(GLOBAL)

add_executable(test-eaccess)

target_link_libraries(test-eaccess PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-eaccess PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-eaccess.c
)

set_target_properties(test-eaccess PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
