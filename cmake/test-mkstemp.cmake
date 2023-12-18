
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)

add_executable(test-mkstemp)

target_link_libraries(test-mkstemp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-mkstemp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-mkstemp.c
)

set_target_properties(test-mkstemp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-mkstemp" COMMAND test-mkstemp)
