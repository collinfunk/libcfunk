
include_guard(GLOBAL)

add_executable(test-__fbufsize)

target_link_libraries(test-__fbufsize PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-__fbufsize PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-__fbufsize.c
)

set_target_properties(test-__fbufsize PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
