
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)

add_executable(test-mkostemp)

target_link_libraries(test-mkostemp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-mkostemp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-mkostemp.c
)

set_target_properties(test-mkostemp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-mkostemp" COMMAND test-mkostemp)
