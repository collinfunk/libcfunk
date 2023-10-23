
include_guard(GLOBAL)

add_executable(test-towlower)

target_link_libraries(test-towlower PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-towlower PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-towlower.c
)

set_target_properties(test-towlower PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-towlower" COMMAND test-towlower)
