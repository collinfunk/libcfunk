
include_guard(GLOBAL)

add_executable(test-physical-memory)

target_link_libraries(test-physical-memory PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-physical-memory PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-physical-memory.c
)

set_target_properties(test-physical-memory PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-physical-memory" COMMAND test-physical-memory)
