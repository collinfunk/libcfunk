
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stat.cmake)

add_executable(test-mkfifo)

target_link_libraries(test-mkfifo PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-mkfifo PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-mkfifo.c
)

set_target_properties(test-mkfifo PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-mkfifo" COMMAND test-mkfifo)
set_tests_properties("test-mkfifo" PROPERTIES SKIP_RETURN_CODE 77)
