
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fileno.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/lseek.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fseeko.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/ftello.cmake)

add_executable(test-fflush)

target_link_libraries(test-fflush PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fflush PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fflush.c
)

set_target_properties(test-fflush PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fflush" COMMAND test-fflush)
