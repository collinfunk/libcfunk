
include_guard(GLOBAL)

add_executable(test-stdio-h)

target_link_libraries(test-stdio-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdio-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdio-h.c
)

set_target_properties(test-stdio-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stdio-h" COMMAND test-stdio-h)
