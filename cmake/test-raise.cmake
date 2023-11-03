
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/_Exit.cmake)

add_executable(test-raise)

target_link_libraries(test-raise PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-raise PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-raise.c
)

set_target_properties(test-raise PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-raise" COMMAND test-raise)
