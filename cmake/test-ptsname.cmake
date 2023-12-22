
include_guard(GLOBAL)

add_executable(test-ptsname)

target_link_libraries(test-ptsname PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-ptsname PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-ptsname.c
)

set_target_properties(test-ptsname PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-ptsname" COMMAND test-ptsname)
