
include_guard(GLOBAL)

add_executable(test-float-h)

target_link_libraries(test-float-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-float-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-float-h.c
)

set_target_properties(test-float-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-float-h" COMMAND test-float-h)
