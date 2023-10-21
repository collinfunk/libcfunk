
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-strerrorname-np)

target_link_libraries(test-strerrorname-np PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strerrorname-np PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strerrorname-np.c
)

set_target_properties(test-strerrorname-np PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strerrorname-np" COMMAND test-strerrorname-np)
