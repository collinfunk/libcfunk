
include_guard(GLOBAL)

add_executable(test-vfork)

target_link_libraries(test-vfork PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-vfork PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-vfork.c
)

set_target_properties(test-vfork PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-vfork" COMMAND test-vfork)
