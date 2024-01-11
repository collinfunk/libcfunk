
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/test-exec-child.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/environ.cmake)

add_executable(test-execle)

target_link_libraries(test-execle PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-execle PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-execle.c
)

set_target_properties(test-execle PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-execle" COMMAND test-execle)
