
include_guard(GLOBAL)

add_executable(test-fdatasync)

target_link_libraries(test-fdatasync PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fdatasync PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fdatasync.c
)

set_target_properties(test-fdatasync PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fdatasync" COMMAND test-fdatasync)
