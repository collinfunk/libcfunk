
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/feof.cmake)

add_executable(test-clearerr)

target_link_libraries(test-clearerr PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-clearerr PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-clearerr.c
)

set_target_properties(test-clearerr PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-clearerr" COMMAND test-clearerr)
