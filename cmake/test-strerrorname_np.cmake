
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-strerrorname_np)

target_link_libraries(test-strerrorname_np PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strerrorname_np PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strerrorname_np.c
)

set_target_properties(test-strerrorname_np PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strerrorname_np" COMMAND test-strerrorname_np)
