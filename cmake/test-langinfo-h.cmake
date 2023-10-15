
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-langinfo-h)

target_link_libraries(test-langinfo-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-langinfo-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-langinfo-h.c
)

set_target_properties(test-langinfo-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
