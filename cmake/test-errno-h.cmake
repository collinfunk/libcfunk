
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-errno-h)

target_link_libraries(test-errno-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-errno-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-errno-h.c
)

set_target_properties(test-errno-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-errno-h" COMMAND test-errno-h)
