
include_guard(GLOBAL)

add_executable(test-exec-child)

target_link_libraries(test-exec-child PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-exec-child PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-exec-child.c
)

set_target_properties(test-exec-child PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

# This file is a test program used by the 'exec' family of functions.
#add_test(NAME "test-exec-child" COMMAND test-exec-child)
