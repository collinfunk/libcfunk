
include_guard(GLOBAL)

add_executable(test-getline)

target_link_libraries(test-getline PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getline PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getline.c
)

set_target_properties(test-getline PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
