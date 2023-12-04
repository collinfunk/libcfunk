
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-argz_stringify)

target_link_libraries(test-argz_stringify PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-argz_stringify PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-argz_stringify.c
)

set_target_properties(test-argz_stringify PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-argz_stringify" COMMAND test-argz_stringify)
