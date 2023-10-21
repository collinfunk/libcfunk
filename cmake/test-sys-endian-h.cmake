
include_guard(GLOBAL)

add_executable(test-sys-endian-h)

target_link_libraries(test-sys-endian-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-endian-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-endian-h.c
)

set_target_properties(test-sys-endian-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sys-endian-h" COMMAND test-sys-endian-h)
