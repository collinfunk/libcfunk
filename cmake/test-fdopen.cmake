
include_guard(GLOBAL)

add_executable(test-fdopen)

target_link_libraries(test-fdopen PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fdopen PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fdopen.c
)

set_target_properties(test-fdopen PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fdopen" COMMAND test-fdopen)
