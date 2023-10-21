
include_guard(GLOBAL)

add_executable(test-hash-map)

target_link_libraries(test-hash-map PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-hash-map PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-hash-map.c
)

set_target_properties(test-hash-map PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-hash-map" COMMAND test-hash-map)
