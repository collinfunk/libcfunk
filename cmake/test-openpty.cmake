
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/read.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/write.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/memcmp.cmake)

add_executable(test-openpty)

target_link_libraries(test-openpty PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-openpty PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-openpty.c
)

set_target_properties(test-openpty PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-openpty" COMMAND test-openpty)
