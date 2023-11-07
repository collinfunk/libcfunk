
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-dirent-h)

target_link_libraries(test-dirent-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-dirent-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-dirent-h.c
)

set_target_properties(test-dirent-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-dirent-h" COMMAND test-dirent-h)
