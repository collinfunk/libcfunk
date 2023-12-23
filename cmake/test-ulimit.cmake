
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/root-uid.cmake)

# Check for 'geteuid'.
check_include_file("unistd.h" HAVE_UNISTD_H)
if (HAVE_UNISTD_H)
  check_symbol_exists("geteuid" "unistd.h" HAVE_GETEUID)
endif ()

add_executable(test-ulimit)

target_link_libraries(test-ulimit PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ulimit PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ulimit.c
)

set_target_properties(test-ulimit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ulimit" COMMAND test-ulimit)
set_tests_properties("test-ulimit" PROPERTIES SKIP_RETURN_CODE 77)
