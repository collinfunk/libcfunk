
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-string-h)

target_link_libraries(test-string-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-string-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-string-h.c
)

set_target_properties(test-string-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-string-h" COMMAND test-string-h)
