
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-utime-h)

target_link_libraries(test-utime-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-utime-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-utime-h.c
)

set_target_properties(test-utime-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
