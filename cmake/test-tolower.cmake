
include_guard(GLOBAL)

check_include_file("windows.h" HAVE_WINDOWS_H)

add_executable(test-tolower)

target_link_libraries(test-tolower PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-tolower PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-tolower.c
)

set_target_properties(test-tolower PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-tolower" COMMAND test-tolower)
