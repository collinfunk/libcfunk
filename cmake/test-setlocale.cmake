
include_guard(GLOBAL)

add_executable(test-setlocale)

target_link_libraries(test-setlocale PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-setlocale PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-setlocale.c
)

set_target_properties(test-setlocale PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-setlocale" COMMAND test-setlocale)
