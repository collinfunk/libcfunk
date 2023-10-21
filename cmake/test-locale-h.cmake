
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-locale-h)

target_link_libraries(test-locale-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-locale-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-locale-h.c
)

set_target_properties(test-locale-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-locale-h" COMMAND test-locale-h)
