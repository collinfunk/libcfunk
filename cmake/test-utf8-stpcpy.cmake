
include_guard(GLOBAL)

add_executable(test-utf8-stpcpy)

target_link_libraries(test-utf8-stpcpy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-utf8-stpcpy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-utf8-stpcpy.c
)

set_target_properties(test-utf8-stpcpy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-utf8-stpcpy" COMMAND test-utf8-stpcpy)
