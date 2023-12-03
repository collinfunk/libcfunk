
include_guard(GLOBAL)

add_executable(test-rand)

target_link_libraries(test-rand PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-rand PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-rand.c
)

set_target_properties(test-rand PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-rand" COMMAND test-rand)
