
include_guard(GLOBAL)

add_executable(test-sys-times-h)

target_link_libraries(test-sys-times-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-times-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-times-h.c
)

set_target_properties(test-sys-times-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sys-times-h" COMMAND test-sys-times-h)
