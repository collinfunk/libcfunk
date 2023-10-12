
include_guard(GLOBAL)

add_executable(test-__fseterr)

target_link_libraries(test-__fseterr PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-__fseterr PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-__fseterr.c
)

set_target_properties(test-__fseterr PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
