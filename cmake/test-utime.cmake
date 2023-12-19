
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)

add_executable(test-utime)

target_link_libraries(test-utime PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-utime PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-utime.c
)

set_target_properties(test-utime PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-utime" COMMAND test-utime)
