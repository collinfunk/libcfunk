
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/mkdir.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)

add_executable(test-remove)

target_link_libraries(test-remove PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-remove PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-remove.c
)

set_target_properties(test-remove PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-remove" COMMAND test-remove)
