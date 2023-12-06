
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/pclose.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-wait-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strcpy.cmake)

add_executable(test-popen)

target_link_libraries(test-popen PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-popen PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-popen.c
)

set_target_properties(test-popen PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-popen" COMMAND test-popen)
