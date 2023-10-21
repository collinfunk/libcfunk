
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)

add_executable(test-access)

target_link_libraries(test-access PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-access PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-access.c
)

set_target_properties(test-access PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-access" COMMAND test-access)
