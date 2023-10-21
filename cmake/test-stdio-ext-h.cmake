
include_guard(GLOBAL)

add_executable(test-stdio-ext-h)

target_link_libraries(test-stdio-ext-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdio-ext-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdio-ext-h.c
)

set_target_properties(test-stdio-ext-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stdio-ext-h" COMMAND test-stdio-ext-h)
