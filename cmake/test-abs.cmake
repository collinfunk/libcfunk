
include_guard(GLOBAL)

add_executable(test-abs)

target_link_libraries(test-abs PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-abs PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-abs.c
)

set_target_properties(test-abs PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-abs" COMMAND test-abs)
