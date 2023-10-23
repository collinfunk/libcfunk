
include_guard(GLOBAL)

add_executable(test-sys-random-h)

target_link_libraries(test-sys-random-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-random-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-random-h.c
)

set_target_properties(test-sys-random-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sys-random-h" COMMAND test-sys-random-h)
