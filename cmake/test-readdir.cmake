
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/opendir.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/closedir.cmake)

add_executable(test-readdir)

target_link_libraries(test-readdir PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-readdir PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-readdir.c
)

set_target_properties(test-readdir PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-readdir" COMMAND test-readdir)
