
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/open.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/read.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/memcmp.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)

add_executable(test-write)

target_link_libraries(test-write PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-write PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-write.c
)

set_target_properties(test-write PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-write" COMMAND test-write)
