
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fseeko.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)

add_executable(test-ftello)

target_link_libraries(test-ftello PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ftello PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ftello.c
)

set_target_properties(test-ftello PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ftello" COMMAND test-ftello)
