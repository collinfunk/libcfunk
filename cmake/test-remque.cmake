
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/insque.cmake)

add_executable(test-remque)

target_link_libraries(test-remque PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-remque PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-remque.c
)

set_target_properties(test-remque PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-remque" COMMAND test-remque)
