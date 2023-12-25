
include_guard(GLOBAL)

add_executable(test-stdalign-h)

target_link_libraries(test-stdalign-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdalign-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdalign-h.c
)

set_target_properties(test-stdalign-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stdalign-h" COMMAND test-stdalign-h)
