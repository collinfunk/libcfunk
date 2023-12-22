
include_guard(GLOBAL)

add_executable(test-ptsname_r)

target_link_libraries(test-ptsname_r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ptsname_r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ptsname_r.c
)

set_target_properties(test-ptsname_r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ptsname_r" COMMAND test-ptsname_r)
