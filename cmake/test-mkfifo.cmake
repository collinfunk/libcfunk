
include_guard(GLOBAL)

add_executable(test-mkfifo)

target_link_libraries(test-mkfifo PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-mkfifo PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-mkfifo.c
)

set_target_properties(test-mkfifo PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
