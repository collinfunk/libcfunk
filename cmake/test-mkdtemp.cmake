
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)

add_executable(test-mkdtemp)

target_link_libraries(test-mkdtemp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-mkdtemp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-mkdtemp.c
)

set_target_properties(test-mkdtemp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-mkdtemp" COMMAND test-mkdtemp)
