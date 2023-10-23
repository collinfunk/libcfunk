
include_guard(GLOBAL)

add_executable(test-sys-time-h)

target_link_libraries(test-sys-time-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-time-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-time-h.c
)

set_target_properties(test-sys-time-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sys-time-h" COMMAND test-sys-time-h)
