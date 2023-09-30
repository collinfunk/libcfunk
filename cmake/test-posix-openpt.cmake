
include_guard(GLOBAL)

add_executable(test-posix-openpt)

target_link_libraries(test-posix-openpt PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-posix-openpt PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-posix-openpt.c
)

set_target_properties(test-posix-openpt PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
