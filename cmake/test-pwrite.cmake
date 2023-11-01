
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/read.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/write.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)

add_executable(test-pwrite)

target_link_libraries(test-pwrite PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-pwrite PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-pwrite.c
)

set_target_properties(test-pwrite PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-pwrite" COMMAND test-pwrite)
