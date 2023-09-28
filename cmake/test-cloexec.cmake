
include_guard(GLOBAL)

add_executable(test-cloexec)

target_link_libraries(test-cloexec PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-cloexec PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-cloexec.c
)

set_target_properties(test-cloexec PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
