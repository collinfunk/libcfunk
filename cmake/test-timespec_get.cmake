
include_guard(GLOBAL)

add_executable(test-timespec_get)

target_link_libraries(test-timespec_get PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-timespec_get PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-timespec_get.c
)

set_target_properties(test-timespec_get PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-timespec_get" COMMAND test-timespec_get)
