
include_guard(GLOBAL)

add_executable(test-utf32-mbtowc)

target_link_libraries(test-utf32-mbtowc PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-utf32-mbtowc PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-utf32-mbtowc.c
)

set_target_properties(test-utf32-mbtowc PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-utf32-mbtowc" COMMAND test-utf32-mbtowc)
