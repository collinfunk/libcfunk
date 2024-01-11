
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strcmp.cmake)

add_executable(test-strsignal)

target_link_libraries(test-strsignal PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strsignal PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strsignal.c
)

set_target_properties(test-strsignal PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-strsignal" COMMAND test-strsignal)
