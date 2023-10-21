
include_guard(GLOBAL)

add_executable(test-filename-macros)

target_link_libraries(test-filename-macros PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-filename-macros PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-filename-macros.c
)

set_target_properties(test-filename-macros PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-filename-macros" COMMAND test-filename-macros)
