
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-fcntl-h)

target_link_libraries(test-fcntl-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fcntl-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fcntl-h.c
)

set_target_properties(test-fcntl-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fcntl-h" COMMAND test-fcntl-h)
