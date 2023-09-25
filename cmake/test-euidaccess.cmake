
include_guard(GLOBAL)

add_executable(test-euidaccess)

target_link_libraries(test-euidaccess PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-euidaccess PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-euidaccess.c
)

set_target_properties(test-euidaccess PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
