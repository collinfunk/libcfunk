
include_guard(GLOBAL)

add_executable(test-getdtablesize)

target_link_libraries(test-getdtablesize PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getdtablesize PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getdtablesize.c
)

set_target_properties(test-getdtablesize PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
