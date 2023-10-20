
include_guard(GLOBAL)

add_executable(test-arc4)

target_link_libraries(test-arc4 PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-arc4 PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-arc4.c
)

set_target_properties(test-arc4 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
