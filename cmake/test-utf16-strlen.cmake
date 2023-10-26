
include_guard(GLOBAL)

add_executable(test-utf16-strlen)

target_link_libraries(test-utf16-strlen PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-utf16-strlen PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-utf16-strlen.c
)

set_target_properties(test-utf16-strlen PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-utf16-strlen" COMMAND test-utf16-strlen)
