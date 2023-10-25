
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memset.cmake)

add_executable(test-bcmp)

target_link_libraries(test-bcmp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-bcmp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-bcmp.c
)

set_target_properties(test-bcmp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-bcmp" COMMAND test-bcmp)
