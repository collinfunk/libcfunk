
include_guard(GLOBAL)

check_include_file("windows.h" HAVE_WINDOWS_H)

add_executable(test-wctype)

target_link_libraries(test-wctype PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wctype PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wctype.c
)

set_target_properties(test-wctype PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wctype" COMMAND test-wctype)
