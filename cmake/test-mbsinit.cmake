
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memset.cmake)

add_executable(test-mbsinit)

target_link_libraries(test-mbsinit PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-mbsinit PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-mbsinit.c
)

set_target_properties(test-mbsinit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-mbsinit" COMMAND test-mbsinit)
