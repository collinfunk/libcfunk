
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memchr.cmake)

add_executable(test-bzero)

target_link_libraries(test-bzero PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-bzero PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-bzero.c
)

set_target_properties(test-bzero PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-bzero" COMMAND test-bzero)
