
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memcmp.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/memset.cmake)

add_executable(test-stpncpy)

target_link_libraries(test-stpncpy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stpncpy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stpncpy.c
)

set_target_properties(test-stpncpy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stpncpy" COMMAND test-stpncpy)
