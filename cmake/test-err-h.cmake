
include_guard(GLOBAL)

add_executable(test-err-h)

target_link_libraries(test-err-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-err-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-err-h.c
)

set_target_properties(test-err-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-err-h" COMMAND test-err-h)
