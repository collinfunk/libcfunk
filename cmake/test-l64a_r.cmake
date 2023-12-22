
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-l64a_r)

target_link_libraries(test-l64a_r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-l64a_r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-l64a_r.c
)

set_target_properties(test-l64a_r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-l64a_r" COMMAND test-l64a_r)
