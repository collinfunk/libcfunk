
include_guard(GLOBAL)

add_executable(test-mbtowc)

target_link_libraries(test-mbtowc PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-mbtowc PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-mbtowc.c
)

set_target_properties(test-mbtowc PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-mbtowc" COMMAND test-mbtowc)
