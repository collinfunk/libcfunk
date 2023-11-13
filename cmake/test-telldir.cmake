
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/opendir.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/closedir.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/rewinddir.cmake)

add_executable(test-telldir)

target_link_libraries(test-telldir PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-telldir PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-telldir.c
)

set_target_properties(test-telldir PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-telldir" COMMAND test-opendir)
