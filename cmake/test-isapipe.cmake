
include_guard(GLOBAL)

add_executable(test-isapipe)

target_link_libraries(test-isapipe PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-isapipe PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-isapipe.c
)

set_target_properties(test-isapipe PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
