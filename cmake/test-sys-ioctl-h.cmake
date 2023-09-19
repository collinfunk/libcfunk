
include_guard(GLOBAL)

add_executable(test-sys-ioctl-h)

target_link_libraries(test-sys-ioctl-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-ioctl-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-ioctl-h.c
)

set_target_properties(test-sys-ioctl-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
