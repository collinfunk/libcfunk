
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-unistd-h)

target_link_libraries(test-unistd-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-unistd-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-unistd-h.c
)

set_target_properties(test-unistd-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-unistd-h" COMMAND test-unistd-h)
