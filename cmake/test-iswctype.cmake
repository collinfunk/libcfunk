
include_guard(GLOBAL)

check_include_file("windows.h" HAVE_WINDOWS_H)

add_executable(test-iswctype)

target_link_libraries(test-iswctype PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-iswctype PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-iswctype.c
)

set_target_properties(test-iswctype PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-iswctype" COMMAND test-iswctype)
