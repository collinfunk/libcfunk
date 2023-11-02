
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sigemptyset.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sigismember.cmake)

add_executable(test-sigaddset)

target_link_libraries(test-sigaddset PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sigaddset PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sigaddset.c
)

set_target_properties(test-sigaddset PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sigaddset" COMMAND test-sigaddset)
