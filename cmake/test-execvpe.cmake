
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/test-exec-child.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/environ.cmake)

add_executable(test-execvpe)

target_link_libraries(test-execvpe PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-execvpe PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-execvpe.c
)

set_target_properties(test-execvpe PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-execvpe" COMMAND test-execvpe)
