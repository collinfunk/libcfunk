
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/opendir.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/closedir.cmake)

add_executable(test-rewinddir)

target_link_libraries(test-rewinddir PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-rewinddir PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-rewinddir.c
)

set_target_properties(test-rewinddir PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-rewinddir" COMMAND test-rewinddir)
