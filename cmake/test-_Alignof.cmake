
include_guard(GLOBAL)

add_executable(test-_Alignof)

target_link_libraries(test-_Alignof PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-_Alignof PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-_Alignof.c
)

set_target_properties(test-_Alignof PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
