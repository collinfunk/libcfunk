
include_guard(GLOBAL)

add_executable(test-utf32-stpcpy)

target_link_libraries(test-utf32-stpcpy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-utf32-stpcpy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-utf32-stpcpy.c
)

set_target_properties(test-utf32-stpcpy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-utf32-stpcpy" COMMAND test-utf32-stpcpy)
