
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-arpa-inet-h)

target_link_libraries(test-arpa-inet-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-arpa-inet-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-arpa-inet-h.c
)

set_target_properties(test-arpa-inet-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-arpa-inet-h" COMMAND test-arpa-inet-h)
