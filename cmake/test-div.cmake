
include_guard(GLOBAL)

add_executable(test-div)

target_link_libraries(test-div PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-div PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-div.c
)

set_target_properties(test-div PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-div" COMMAND test-div)
