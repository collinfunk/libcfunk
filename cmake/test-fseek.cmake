
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)

add_executable(test-fseek)

target_link_libraries(test-fseek PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fseek PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fseek.c
)

set_target_properties(test-fseek PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fseek" COMMAND test-fseek)
