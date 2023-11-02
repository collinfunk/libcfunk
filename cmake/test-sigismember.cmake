
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sigemptyset.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sigfillset.cmake)

add_executable(test-sigismember)

target_link_libraries(test-sigismember PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sigismember PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sigismember.c
)

set_target_properties(test-sigismember PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sigismember" COMMAND test-sigismember)
