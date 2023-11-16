
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-netinet-in-h)

target_link_libraries(test-netinet-in-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-netinet-in-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-netinet-in-h.c
)

set_target_properties(test-netinet-in-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-netinet-in-h" COMMAND test-netinet-in-h)
