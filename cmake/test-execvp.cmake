
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/test-exec-child.cmake)

add_executable(test-execvp)

target_link_libraries(test-execvp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-execvp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-execvp.c
)

set_target_properties(test-execvp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-execvp" COMMAND test-execvp)
