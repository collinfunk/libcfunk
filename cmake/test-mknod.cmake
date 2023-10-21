
include_guard(GLOBAL)

add_executable(test-mknod)

target_link_libraries(test-mknod PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-mknod PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-mknod.c
)

set_target_properties(test-mknod PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-mknod" COMMAND test-mknod)
