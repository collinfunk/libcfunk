
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)

add_executable(test-unlink)

target_link_libraries(test-unlink PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-unlink PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-unlink.c
)

set_target_properties(test-unlink PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-unlink" COMMAND test-unlink)
