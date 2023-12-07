
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-monetary-h)

target_link_libraries(test-monetary-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-monetary-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-monetary-h.c
)

set_target_properties(test-monetary-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-monetary-h" COMMAND test-monetary-h)
