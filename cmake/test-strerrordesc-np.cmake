
include_guard(GLOBAL)

add_executable(test-strerrordesc-np)

target_link_libraries(test-strerrordesc-np PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-strerrordesc-np PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-strerrordesc-np.c
)

set_target_properties(test-strerrordesc-np PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
