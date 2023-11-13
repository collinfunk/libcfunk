
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/opendir.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/closedir.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/telldir.cmake)

add_executable(test-seekdir)

target_link_libraries(test-seekdir PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-seekdir PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-seekdir.c
)

set_target_properties(test-seekdir PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-seekdir" COMMAND test-seekdir)
