
include_guard(GLOBAL)

add_executable(test-__func__)

target_link_libraries(test-__func__ PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-__func__ PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-__func__.c
)

set_target_properties(test-__func__ PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)