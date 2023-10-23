
include_guard(GLOBAL)

add_executable(test-iswalnum)

target_link_libraries(test-iswalnum PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswalnum PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswalnum.c
)

set_target_properties(test-iswalnum PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswalnum" COMMAND test-iswalnum)
