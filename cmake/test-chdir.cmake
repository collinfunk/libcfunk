
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/mkdir.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/rmdir.cmake)

add_executable(test-chdir)

target_link_libraries(test-chdir PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-chdir PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-chdir.c
)

set_target_properties(test-chdir PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
