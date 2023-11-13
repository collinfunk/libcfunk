
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/closedir.cmake)

add_executable(test-opendir)

target_link_libraries(test-opendir PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-opendir PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-opendir.c
)

set_target_properties(test-opendir PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-opendir" COMMAND test-opendir)
