
include_guard(GLOBAL)

add_executable(test-explicit_bzero)

target_link_libraries(test-explicit_bzero PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-explicit_bzero PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-explicit_bzero.c
)

set_target_properties(test-explicit_bzero PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-explicit_bzero" COMMAND test-explicit_bzero)
