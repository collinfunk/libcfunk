
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-strcat)

target_link_libraries(test-strcat PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strcat PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strcat.c
)

set_target_properties(test-strcat PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strcat" COMMAND test-strcat)
