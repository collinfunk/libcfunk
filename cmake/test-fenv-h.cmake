
include_guard(GLOBAL)

add_executable(test-fenv-h)

target_link_libraries(test-fenv-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fenv-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fenv-h.c
)

set_target_properties(test-fenv-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fenv-h" COMMAND test-fenv-h)
