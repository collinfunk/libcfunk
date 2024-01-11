
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/test-exec-child.cmake)

add_executable(test-execlp)

target_link_libraries(test-execlp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-execlp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-execlp.c
)

set_target_properties(test-execlp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-execlp" COMMAND test-execlp)
