
include_guard(GLOBAL)

add_executable(test-inttypes-h)

target_link_libraries(test-inttypes-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-inttypes-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-inttypes-h.c
)

set_target_properties(test-inttypes-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-inttypes-h" COMMAND test-inttypes-h)
