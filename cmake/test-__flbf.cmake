
include_guard(GLOBAL)

add_executable(test-__flbf)

target_link_libraries(test-__flbf PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-__flbf PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-__flbf.c
)

set_target_properties(test-__flbf PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
