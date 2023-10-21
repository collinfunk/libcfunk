
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/open.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/write.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fstat.cmake)

add_executable(test-ftruncate)

target_link_libraries(test-ftruncate PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ftruncate PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ftruncate.c
)

set_target_properties(test-ftruncate PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ftruncate" COMMAND test-ftruncate)
