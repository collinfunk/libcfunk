
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fseeko.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)

add_executable(test-ftell)

target_link_libraries(test-ftell PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ftell PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ftell.c
)

set_target_properties(test-ftell PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ftell" COMMAND test-ftell)
