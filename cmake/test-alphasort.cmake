
include_guard(GLOBAL)

add_executable(test-alphasort)

target_link_libraries(test-alphasort PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-alphasort PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-alphasort.c
)

set_target_properties(test-alphasort PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-alphasort" COMMAND test-alphasort)
