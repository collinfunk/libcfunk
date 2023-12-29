
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/open.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/mkdir.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/getcwd.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)

add_executable(test-fchdir)

target_link_libraries(test-fchdir PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fchdir PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fchdir.c
)

set_target_properties(test-fchdir PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fchdir" COMMAND test-fchdir)
set_tests_properties("test-fchdir" PROPERTIES SKIP_RETURN_CODE 77)
