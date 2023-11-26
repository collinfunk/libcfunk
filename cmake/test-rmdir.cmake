
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/mkdir.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)

add_executable(test-rmdir)

target_link_libraries(test-rmdir PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-rmdir PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-rmdir.c
)

set_target_properties(test-rmdir PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-rmdir" COMMAND test-rmdir)
