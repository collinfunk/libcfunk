
include_guard(GLOBAL)

add_executable(test-sysexits-h)

target_link_libraries(test-sysexits-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sysexits-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sysexits-h.c
)

set_target_properties(test-sysexits-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sysexits-h" COMMAND test-sysexits-h)
