
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/memcmp.cmake)

add_executable(test-rewind)

target_link_libraries(test-rewind PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-rewind PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-rewind.c
)

set_target_properties(test-rewind PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-rewind" COMMAND test-rewind)
