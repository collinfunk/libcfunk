
include_guard(GLOBAL)

add_executable(test-null-device)

target_link_libraries(test-null-device PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-null-device PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-null-device.c
)

set_target_properties(test-null-device PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-null-device" COMMAND test-null-device)
