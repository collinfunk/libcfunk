
include_guard(GLOBAL)

add_executable(test-pthread-h)

target_link_libraries(test-pthread-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-pthread-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-pthread-h.c
)

set_target_properties(test-pthread-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-pthread-h" COMMAND test-pthread-h)
